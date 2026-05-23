#define _GNU_SOURCE
#include <ftw.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <limits.h>
#include <errno.h>
#include <sys/stat.h>
#include <openssl/sha.h>  // aggiunge -lssl -lcrypto


static void sha1_of_file(const char *path, char out_hex[41]) {
    FILE *f = fopen(path, "rb");
    if (!f) { perror("fopen"); out_hex[0] = '\0'; return; }

    SHA_CTX ctx;
    SHA1_Init(&ctx);
    unsigned char buf[65536];
    size_t n;
    while ((n = fread(buf, 1, sizeof(buf), f)) > 0)
        SHA1_Update(&ctx, buf, n);
    fclose(f);

    unsigned char digest[SHA_DIGEST_LENGTH];
    SHA1_Final(digest, &ctx);
    for (int i = 0; i < SHA_DIGEST_LENGTH; i++)
        sprintf(out_hex + i*2, "%02x", digest[i]);
    out_hex[40] = '\0';
}

static char sha1root[PATH_MAX];  // path assoluto di .sha1index, settato una volta
int callback(const char *fpath, const struct stat *sb, int typeflag, struct FTW *ftwbuf) {
    if (strcmp(fpath + ftwbuf->base, ".sha1index") == 0)
        return FTW_SKIP_SUBTREE;
    if (typeflag != FTW_D)
        return 0;

    if (ftwbuf->level == 0) {
        snprintf(sha1root, sizeof(sha1root), "%s/.sha1index", fpath);
        if (mkdir(sha1root, 0755) == -1 && errno != EEXIST) {
            perror("mkdir");
            return EXIT_FAILURE;
        }
    }

    DIR *dir = opendir(fpath);
    if (!dir) {
        perror("opendir");
        return EXIT_FAILURE;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 ||
            strcmp(entry->d_name, "..") == 0 ||
            strcmp(entry->d_name, ".sha1index") == 0)
            continue;

        char fullpath[PATH_MAX];
        snprintf(fullpath, sizeof(fullpath), "%s/%s", fpath, entry->d_name);

        struct stat st;
        if (lstat(fullpath, &st) == -1) {
            perror("lstat");
            continue;
        }

        if (!S_ISREG(st.st_mode))
            continue;

        char sha1hex[41];
        sha1_of_file(fullpath, sha1hex);
        if (sha1hex[0] == '\0')
            continue;

        char linkpath[PATH_MAX];
        snprintf(linkpath, sizeof(linkpath), "%s/%s", sha1root, sha1hex);

        if (symlink(fullpath, linkpath) == -1 && errno != EEXIST) {
            perror("symlink");
            closedir(dir);
            return EXIT_FAILURE;
        }
    }

    closedir(dir);
    return 0;
}

int main(int argc, char **argv) {
    if (argc > 2) {
        printf("sha1index [folder_path]\n");
        return EXIT_FAILURE;
    }

    char fpath[PATH_MAX];
    if (argc == 1) strcpy(fpath, "./");
    else strcpy(fpath, argv[1]);

    nftw(fpath, callback, 20, FTW_PHYS | FTW_ACTIONRETVAL);
    return EXIT_SUCCESS;
}