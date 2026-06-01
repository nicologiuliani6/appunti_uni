#define _XOPEN_SOURCE 500
#include <ftw.h> //NFTW
#include <stdio.h>
#include <dirent.h> //DIR
#include <sys/types.h> //TIPI STRANI
#include <stdlib.h> //EXIT
#include <sys/stat.h> //struct st
#include <string.h> //strcpy

typedef struct s_file {
    ino_t inode;
    off_t byte_size;
} s_file;


s_file* return_files(char *file_path) {
    s_file* F = malloc(sizeof(s_file));

    struct stat st;
    if (stat(file_path, &st) == -1) {
        perror("stat");
        exit(1);
    }
    if (!S_ISREG(st.st_mode)){
        printf("File non combatibile!\n");
        exit(1);
    }

    F->inode = st.st_ino;
    F->byte_size = st.st_size;

    return F;
}
s_file* F = NULL;
int callback(const char *fpath, const struct stat *sb, int typeflag, struct FTW *ftwbuf) {
    if (typeflag != FTW_F)  // salta tutto ciò che non è file regolare
        return 0;
    if (sb->st_ino != F->inode && sb->st_size == F->byte_size) {
        printf("%s\n", fpath);
    }
    return 0;
}

int main(int argc, char** argv){
    if (argc != 3) {
        printf("samecont: [file] [dir]\n" );
        return 1;
    }
    F = return_files(argv[1]);
    if (nftw(argv[2], callback, 20, FTW_PHYS) == -1) {
        perror("nftw");
        return 1;
    }   
    return 0;
}