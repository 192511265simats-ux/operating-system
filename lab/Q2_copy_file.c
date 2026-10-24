// Q2: Copy contents from one file to another using system calls
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(void) {
    char source[256], destination[256], buffer[4096];
    ssize_t bytes_read;
    int src, dst;

    printf("Enter source filename: ");
    if (scanf("%255s", source) != 1) return 1;
    printf("Enter destination filename: ");
    if (scanf("%255s", destination) != 1) return 1;

    src = open(source, O_RDONLY);
    if (src < 0) { perror("Cannot open source"); return 1; }

    dst = open(destination, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dst < 0) { perror("Cannot open destination"); close(src); return 1; }

    while ((bytes_read = read(src, buffer, sizeof(buffer))) > 0) {
        ssize_t total_written = 0;
        while (total_written < bytes_read) {
            ssize_t n = write(dst, buffer + total_written, bytes_read - total_written);
            if (n < 0) { perror("write failed"); close(src); close(dst); return 1; }
            total_written += n;
        }
    }

    if (bytes_read < 0) perror("read failed");
    close(src);
    close(dst);
    if (bytes_read < 0) return 1;

    printf("File copied successfully.\n");
    return 0;
}
