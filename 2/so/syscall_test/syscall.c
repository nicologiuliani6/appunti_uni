#include <stdio.h>   // per perror()
#include <fcntl.h>   // per open() e flag O_RDONLY, O_CREAT, ecc.
#include <unistd.h>  // per read() e write()
#include <stdlib.h> //malloc
#include <stdint.h>

int main(void) {
    char msg[] = "Ciao da OpenBSD\n";
    write(1, msg, sizeof(msg));  // 1 = stdout

    const char *filename = "test.txt";
    // Apri in lettura
    int32_t fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }
    
    char* buf = malloc(128);
    ssize_t n = read(fd, buf, sizeof(buf));
    if (n == -1) {
        perror("read");
        close(fd);
        return 1;
    }

    write(1, buf, n);  // scrive su stdout
    close(fd);         // chiude il file descriptor

    free(buf);
    return 0;
}

