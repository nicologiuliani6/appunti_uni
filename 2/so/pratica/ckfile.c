#define _XOPEN_SOURCE 500
#include <ftw.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
/*
Scrivi un programma C ckfile che prende come parametri un'opzione, il pathname di un file f e di una directory d:
    ckfile -s /tmp/file /tmp    # elenca i symlink che puntano a f nel sottoalbero di d
    ckfile -l /tmp/file /tmp    # elenca gli hard link di f nel sottoalbero di d
*/

typedef enum {
    HARDLINK,
    SYMLINK
} SEARCH_MODE;

typedef struct ckfile {
    char *fname;
    char *dirname;
    SEARCH_MODE mode;
    struct stat st;
} *ck;

ck F;
int callback(const char *fpath, const struct stat *sb, int typeflag, struct FTW *ftwbuf)
{
    if (F->mode == HARDLINK) {
        if (typeflag != FTW_F)
            return 0;
        //controllo su inode non basta perche dobbiamo omettere il file originale
        char *resolved = realpath(fpath, NULL);
        if (sb->st_ino == F->st.st_ino
            && sb->st_dev == F->st.st_dev
            && strcmp(resolved, F->fname) != 0)
            printf("%s\n", fpath);
        free(resolved);
    } else {
        if (typeflag != FTW_SL)
            return 0;
        char buf[4096];
        ssize_t n = readlink(fpath, buf, sizeof(buf) - 1);
        if (n < 0)
            return 0;
        buf[n] = '\0';
        char *resolved_link = realpath(buf, NULL);
        if (resolved_link && strcmp(resolved_link, F->fname) == 0)
            printf("%s\n", fpath);
        free(resolved_link);
    }
    return 0;
}

int main(int argc, char **argv)
{
    if (argc != 4) {
        printf("ckfile: -[mode] [file_path] [dir_path]\n");
        printf("\t-s (symlink)\n");
        printf("\t-l (hardlink)\n");
        return 1;
    }

    F = malloc(sizeof(struct ckfile));
    F->fname = realpath(argv[2], NULL);
    F->dirname = argv[3];

    if (strcmp(argv[1], "-l") == 0)
        F->mode = HARDLINK;
    else if (strcmp(argv[1], "-s") == 0)
        F->mode = SYMLINK;
    else {
        printf("Modalita' non valida!\n");
        return 2;
    }

    if (stat(F->fname, &F->st) < 0) {
        perror(F->fname);
        return 3;
    }

    nftw(F->dirname, callback, 20, FTW_PHYS);
    free(F->fname);
    free(F);
    return 0;
}