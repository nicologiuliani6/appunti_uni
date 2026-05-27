#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <limits.h>

int main(void) {
    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        perror("getcwd");
        return 1;
    }

    DIR *dir = opendir(".");
    if (!dir) { perror("opendir"); return 1; }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 ||
            strcmp(entry->d_name, "..") == 0)
            continue;

        struct stat st;
        if (stat(entry->d_name, &st) == -1) continue;
        if (!S_ISREG(st.st_mode))           continue;

        // Path assoluto del file
        char fullpath[PATH_MAX];
        snprintf(fullpath, sizeof(fullpath), "%s/%s", cwd, entry->d_name);

        // Legge il contenuto del file
        FILE *f = fopen(entry->d_name, "rb");
        if (!f) continue;

        fseek(f, 0, SEEK_END);
        long fsize = ftell(f);
        rewind(f);

        if (fsize <= 0) { fclose(f); continue; }

        char *buf = malloc(fsize);
        if (!buf) { fclose(f); continue; }
        fread(buf, 1, fsize, f);
        fclose(f);

        // Cerca il proprio path dentro se stesso
        size_t plen = strlen(fullpath);
        for (size_t i = 0; i + plen <= (size_t)fsize; i++) {
            if (memcmp(buf + i, fullpath, plen) == 0) {
                printf("%s\n", entry->d_name);
                break;
            }
        }

        free(buf);
    }

    closedir(dir);
    return 0;
}