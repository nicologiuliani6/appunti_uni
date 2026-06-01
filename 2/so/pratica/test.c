#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h> //DIR*
#include <limits.h>
#include <sys/stat.h>

char **vreaddir(const char *path);
int main(){
    char* buffer =".";
    char** result = vreaddir(buffer);
    while(*result != NULL){
        printf("%s\n", *result);
        result++;
    }
}

char **vreaddir(const char *path) {
    int count = 0;
    char **list = malloc(sizeof(char *));
    list[0] = NULL;

    DIR *dir = opendir(path);
    if (!dir) return NULL;

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 ||
            strcmp(entry->d_name, "..") == 0)
            continue;

        list = realloc(list, (count + 2) * sizeof(char *));
        list[count] = strdup(entry->d_name);
        count++;
        list[count] = NULL;
    }

    closedir(dir);
    return list;
}