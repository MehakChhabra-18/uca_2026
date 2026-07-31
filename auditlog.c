#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define LOGFILE "audit.log"
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    if (argc < 2) {
        write(STDOUT_FILENO, "Usage:\n./auditlog --add \"message\"\n./auditlog --view\n", 53);
        return 1;
    }

    // Add a log entry
    if (strcmp(argv[1], "--add") == 0) {

        if (argc < 3) {
            write(STDOUT_FILENO, "No message provided.\n", 21);
            return 1;
        }

        int fd = open(LOGFILE, O_WRONLY | O_CREAT | O_APPEND, 0644);

        if (fd < 0) {
            perror("open");
            return 1;
        }

        write(fd, argv[2], strlen(argv[2]));
        write(fd, "\n", 1);

        close(fd);
    }

    // View log entries
    else if (strcmp(argv[1], "--view") == 0) {

        int fd = open(LOGFILE, O_RDONLY);

        if (fd < 0) {
            perror("open");
            return 1;
        }

        char ch;
        int line = 1;
        char num[20];

        sprintf(num, "%d: ", line);
        write(STDOUT_FILENO, num, strlen(num));

        while (read(fd, &ch, 1) > 0) {
            write(STDOUT_FILENO, &ch, 1);

            if (ch == '\n') {
                line++;
                sprintf(num, "%d: ", line);
                write(STDOUT_FILENO, num, strlen(num));
            }
        }

        close(fd);
    }

    else {
        write(STDOUT_FILENO, "Invalid option.\n", 16);
        return 1;
    }

    return 0;
}
