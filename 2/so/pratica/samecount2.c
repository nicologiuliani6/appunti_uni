#define _XOPEN_SOURCE 700
#include <ftw.h> //NFTW
#include <stdio.h>
#include <dirent.h> //DIR
#include <sys/types.h> //TIPI STRANI
#include <stdlib.h> //EXIT
#include <sys/stat.h> //struct st
#include <string.h> //strcpy
#include <limits.h> //PATH_MAX
#include <unistd.h> //readlink

char real_f[PATH_MAX];
int callback(const char *fpath, const struct stat *sb, int typeflag, struct FTW *ftwbuf) {
    if (typeflag != FTW_SL)  // salta tutto ciò che non è file regolare
        return 0;

    char buf[PATH_MAX];
    ssize_t len = readlink(fpath, buf, sizeof(buf) - 1); //copiamo il path che punta il syslink
    if (len == -1) return 0;
    buf[len] = '\0';

    char abs_buf[PATH_MAX];
    if (buf[0] != '/') {
        // path relativo: costruisci partendo dalla dir del symlink
        char tmp[PATH_MAX];
        strcpy(tmp, fpath);          // es. dir/link.txt
        char *slash = strrchr(tmp, '/');
        if (slash) *(slash + 1) = '\0';  // tmp = "dir/"
        else strcpy(tmp, "./");
        strcat(tmp, buf);            // tmp = "dir/../t.txt"
        realpath(tmp, abs_buf);
    } else {
        realpath(buf, abs_buf);
    }

    if (strcmp(real_f, abs_buf) == 0)
        printf("%s\n", fpath);
    return 0;
}

int main(int argc, char** argv){
    if (argc != 3) {
        printf("samecont: [file] [dir]\n" );
        return 1;
    }
    realpath(argv[1], real_f);      // path canonico di f
    if (nftw(argv[2], callback, 20, FTW_PHYS) == -1) {
        perror("nftw");
        return 1;
    }   
    return 0;
}