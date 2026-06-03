#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <sys/timerfd.h>
#include <ctype.h>
#include <stdint.h>
#include <unistd.h>

int main(int argc, char** argv)
{
    if (argc != 2) {
        fprintf(stderr, "usage: %s iter,interval,msg\n", argv[0]);
        return EXIT_FAILURE;
    }

    int iter = 0;
    float interval_f = 0;
    char msg[100];

    sscanf(argv[1], "%d,%f,%99[^,]", &iter, &interval_f, msg);

    int tfd = timerfd_create(CLOCK_MONOTONIC, 0);
    if (tfd == -1) {
        perror("timerfd_create");
        return EXIT_FAILURE;
    }

    struct itimerspec ts = {0};

    ts.it_value.tv_sec = (time_t)interval_f;
    ts.it_value.tv_nsec = (interval_f - ts.it_value.tv_sec) * 1e9;

    ts.it_interval = ts.it_value;

    timerfd_settime(tfd, 0, &ts, NULL);

    struct timespec start;
    clock_gettime(CLOCK_MONOTONIC, &start);

    for (int i = 0; i < iter; i++) {
        uint64_t expirations;
        read(tfd, &expirations, sizeof(expirations));

        struct timespec now;
        clock_gettime(CLOCK_MONOTONIC, &now);

        double elapsed =
            (now.tv_sec - start.tv_sec) +
            (now.tv_nsec - start.tv_nsec) / 1e9;

        printf("%.6f %s\n", elapsed, msg);
    }

    close(tfd);
    return EXIT_SUCCESS;
}