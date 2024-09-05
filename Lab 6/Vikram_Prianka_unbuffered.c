#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>

#define BUF_SIZE 1024

void unbuffered_io(const char *filename, const char *str) {
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    time_t start_time = time(NULL);

    for (int i = 0; i < 1000000; ++i) {
        write(fd, str, strlen(str));
        write(fd, "\n", 1); // Add newline for clarity
    }

    time_t end_time = time(NULL);
    printf("Time taken for unbuffered IO: %ld seconds\n", end_time - start_time);

    close(fd);
}

void buffered_io(const char *filename, const char *str) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    time_t start_time = time(NULL);

    for (int i = 0; i < 1000000; ++i) {
        fprintf(file, "%s\n", str);
    }

    time_t end_time = time(NULL);
    printf("Time taken for buffered IO: %ld seconds\n", end_time - start_time);

    fclose(file);
}

int main() {
    const char *filename = "output.txt";
    const char *str = "Hello, World!";

    printf("Starting unbuffered IO...\n");
    unbuffered_io(filename, str);

    printf("\nStarting buffered IO...\n");
    buffered_io(filename, str);

    return 0;
}
