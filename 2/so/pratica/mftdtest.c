#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/timerfd.h>
#include <time.h>

typedef struct {
    int iter;
    float interval_f;
    char msg[100];
} data;

typedef struct {
    double time;
    char msg[100];
} event;

typedef struct {
    data *d;
} thread_arg;

/* ---- GLOBAL EVENT BUFFER ---- */

event *events = NULL;
int event_count = 0;
int event_capacity = 0;

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

/* ---- PUSH EVENT (THREAD SAFE) ---- */

void push_event(double t, const char *msg) {
    pthread_mutex_lock(&lock);

    if (event_count >= event_capacity) {
        event_capacity *= 2;
        events = realloc(events, event_capacity * sizeof(event));
        if (!events) {
            perror("realloc");
            exit(1);
        }
    }

    events[event_count].time = t;
    strncpy(events[event_count].msg, msg, 99);
    events[event_count].msg[99] = '\0';
    event_count++;

    pthread_mutex_unlock(&lock);
}

/* ---- THREAD ---- */

void *worker(void *arg) {
    data *D = ((thread_arg *)arg)->d;

    int tfd = timerfd_create(CLOCK_MONOTONIC, 0);
    if (tfd == -1) {
        perror("timerfd_create");
        return NULL;
    }

    struct itimerspec ts = {0};

    ts.it_value.tv_sec = (time_t)D->interval_f;
    ts.it_value.tv_nsec = (D->interval_f - ts.it_value.tv_sec) * 1e9;
    ts.it_interval = ts.it_value;

    timerfd_settime(tfd, 0, &ts, NULL);

    struct timespec start;
    clock_gettime(CLOCK_MONOTONIC, &start);

    for (int i = 0; i < D->iter; i++) {
        uint64_t expirations;
        read(tfd, &expirations, sizeof(expirations));

        struct timespec now;
        clock_gettime(CLOCK_MONOTONIC, &now);

        double elapsed =
            (now.tv_sec - start.tv_sec) +
            (now.tv_nsec - start.tv_nsec) / 1e9;

        push_event(elapsed, D->msg);
    }

    close(tfd);
    return NULL;
}

/* ---- SORT ---- */

int cmp(const void *a, const void *b) {
    double t1 = ((event *)a)->time;
    double t2 = ((event *)b)->time;
    return (t1 > t2) - (t1 < t2);
}

/* ---- REPLAY CON TIMERFD ---- */

void replay_with_timerfd() {
    int tfd = timerfd_create(CLOCK_MONOTONIC, 0);
    if (tfd == -1) {
        perror("timerfd_create replay");
        exit(1);
    }

    for (int i = 0; i < event_count; i++) {

        double dt;

        if (i == 0) {
            dt = events[i].time;
        } else {
            dt = events[i].time - events[i - 1].time;
        }

        if (dt > 0) {
            struct itimerspec ts = {0};

            ts.it_value.tv_sec = (time_t)dt;
            ts.it_value.tv_nsec = (dt - ts.it_value.tv_sec) * 1e9;

            timerfd_settime(tfd, 0, &ts, NULL);

            uint64_t expirations;
            read(tfd, &expirations, sizeof(expirations));
        }

        printf("%.6f %s\n", events[i].time, events[i].msg);
    }

    close(tfd);
}

/* ---- MAIN ---- */

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "usage: %s iter,interval,msg ...\n", argv[0]);
        return EXIT_FAILURE;
    }

    int n = argc - 1;

    data *db = malloc(n * sizeof(data));
    pthread_t *threads = malloc(n * sizeof(pthread_t));
    thread_arg *args = malloc(n * sizeof(thread_arg));

    /* init buffer */
    event_capacity = 16;
    events = malloc(event_capacity * sizeof(event));
    event_count = 0;

    /* parse */
    for (int i = 0; i < n; i++) {
        sscanf(argv[i + 1], "%d,%f,%99[^,]",
               &db[i].iter,
               &db[i].interval_f,
               db[i].msg);
    }

    /* threads */
    for (int i = 0; i < n; i++) {
        args[i].d = &db[i];
        pthread_create(&threads[i], NULL, worker, &args[i]);
    }

    for (int i = 0; i < n; i++) {
        pthread_join(threads[i], NULL);
    }

    /* sort global events */
    qsort(events, event_count, sizeof(event), cmp);

    /* replay using timerfd */
    replay_with_timerfd();

    /* cleanup */
    free(db);
    free(threads);
    free(args);
    free(events);

    return 0;
}