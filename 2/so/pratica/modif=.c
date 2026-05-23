#include <stdio.h> //printf
#include <string.h> //strcmp
#include <time.h> //time_t e time()
#include <dirent.h> //DIR*
#include <stdlib.h> //EXIT
#include <sys/stat.h> //struct stat
#include <sys/types.h> //ino_t

time_t time_file(const char *fpath){
    struct stat fileStat;
    if (stat(fpath, &fileStat) != 0) {
        perror("stat");
        exit(1);
    }
    return fileStat.st_mtime;
}

time_t t_base;
ino_t inode_base;
void scan_dir(const char *path) {
    DIR *dir = opendir(path);
    if (!dir) return;

    struct dirent *entry;

    while ((entry = readdir(dir)) != NULL) {

        // skip . e ..
        if (strcmp(entry->d_name, ".") == 0 ||
            strcmp(entry->d_name, "..") == 0)
            continue;

        // costruisci path completo
        char fullpath[1024];
        snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);

        struct stat st;
        if (lstat(fullpath, &st) == -1) continue; //escludiamo softlink

        if (S_ISDIR(st.st_mode)) {
            //ricorsione
            scan_dir(fullpath);
        } else if (S_ISREG(st.st_mode)){ 
            ino_t inode_local = st.st_ino;
            if(time_file(fullpath) == t_base && inode_local != inode_base) //controlliamo anche che inode sia diverso (NON HARDLINK)
                printf("%s\n", fullpath);
        }
    }

    closedir(dir);
}

int main(int argc, char** argv){
    if (argc == 2){
        //modalita 1
        t_base = time_file(argv[1]);
        struct stat st;
        if (stat(argv[1], &st) == -1) {
            perror("stat");
            return 1;
        }
        inode_base = st.st_ino; //salviamo inode del file
            //iteriamo tutti gli altri file
            scan_dir(".");
    } else if(argc == 3){
        //mod. 2
        struct stat fileStat[2];
        if (lstat(argv[1], &fileStat[0]) != 0) {
            perror("stat file n.1");
            exit(1);
        } else if (lstat(argv[2], &fileStat[1]) != 0) {
            perror("stat file/dir n.2");
            exit(1);
        }
        struct stat st;
        if (stat(argv[1], &st) == -1) {
            perror("stat");
            return 1;
        }
        inode_base = st.st_ino;
        if (S_ISDIR(fileStat[1].st_mode)){
            //cartella
            t_base = time_file(argv[1]);
            scan_dir(argv[2]);
        } else if (S_ISREG(fileStat[1].st_mode)){
            ino_t inode_local = fileStat[1].st_ino;
            //file regolare
            if (time_file(argv[2]) == time_file(argv[1]) && inode_base != inode_local){
                printf("%s\n", argv[2]);
            }
        } 

    } else{
        printf("USAGE: \n");
        return 1;
    }
    return 0;
}