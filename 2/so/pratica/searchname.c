#define _XOPEN_SOURCE 500
#include <ftw.h>
#include <stdio.h>
#include <string.h>
//dato un nome di un file cercare quei file ESEGUIBILI e dire se sono ELF o script 
int is_elf(const char *path) {

    FILE *f = fopen(path, "rb");
    if(f == NULL)
        return 0;

    unsigned char buf[4];

    size_t n = fread(buf, 1, 4, f);
    fclose(f);

    if(n < 4)
        return 0;

    return
        buf[0] == 0x7f &&
        buf[1] == 'E' &&
        buf[2] == 'L' &&
        buf[3] == 'F';
}

int is_script(const char *path) {

    FILE *f = fopen(path, "rb");
    if(f == NULL)
        return 0;

    unsigned char buf[2];

    size_t n = fread(buf, 1, 2, f);
    fclose(f);

    if(n < 2)
        return 0;

    return buf[0] == '#' && buf[1] == '!';
}
char* fname;
int callback(const char *fpath, const struct stat *sb, int typeflag, struct FTW *ftwbuf)
{
    //printf("%s\n", fname); //nome file da cercare
    if (typeflag == FTW_F && strcmp(fpath + ftwbuf->base, fname) == 0 && (sb->st_mode & S_IXUSR)){
        printf("%s: ", fpath);
        if(is_elf(fpath)) {
            printf("ELF executable\n");
        }
        else if(is_script(fpath)) {
            printf("script\n");
        }
    }
    return 0;
}

int main(int argc, char** argv){
    if (argc == 1 ) {
        printf("Inserire il nome del file!\n");
        return 1;
    }
    fname = argv[1];
    nftw(".", callback, 20, FTW_PHYS);
}