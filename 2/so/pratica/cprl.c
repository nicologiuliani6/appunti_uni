#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <limits.h>

int link_dir(const char *src, const char *dst) {
    /* Crea dst se non esiste */
    if (mkdir(dst, 0755) == -1 && errno != EEXIST) {
        perror("mkdir");
        return EXIT_FAILURE;
    }

    DIR *d_src = opendir(src);
    if (!d_src) {
        perror(src);
        return EXIT_FAILURE;
    }

    struct dirent *entry;
    int ret = EXIT_SUCCESS;

    while ((entry = readdir(d_src)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 ||
            strcmp(entry->d_name, "..") == 0)
            continue;

        char from[PATH_MAX], to[PATH_MAX];
        snprintf(from, sizeof(from), "%s/%s", src, entry->d_name);
        snprintf(to,   sizeof(to),   "%s/%s", dst, entry->d_name);

        struct stat st;
        if (lstat(from, &st) == -1) {   /* BUG 3 fix */
            perror(from);
            ret = EXIT_FAILURE;
            continue;
        }

        if (S_ISDIR(st.st_mode)) {
            if (link_dir(from, to) != EXIT_SUCCESS)  /* BUG 4 fix */
                ret = EXIT_FAILURE;

        } else if (S_ISLNK(st.st_mode)) {            /* BUG 2 fix */
            char target[PATH_MAX];
            ssize_t len = readlink(from, target, sizeof(target) - 1);
            if (len == -1) {
                perror(from);
                ret = EXIT_FAILURE;
            } else {
                target[len] = '\0';
                if (symlink(target, to) == -1 && errno != EEXIST) {
                    perror(to);
                    ret = EXIT_FAILURE;
                }
            }

        } else {
            if (link(from, to) == -1 && errno != EEXIST) {
                perror(to);
                ret = EXIT_FAILURE;
            }
        }
    }

    closedir(d_src);
    return ret;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "usage: %s src dst\n", argv[0]);
        return EXIT_FAILURE;
    }
    return link_dir(argv[1], argv[2]);
}