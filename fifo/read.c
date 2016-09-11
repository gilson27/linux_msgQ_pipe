#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_BUF 1024

int main()
{
    int fd;
    char *fifoLoc = "/tmp/ipc_fifo";
    char buf[MAX_BUF];


    fd = open(fifoLoc, O_RDONLY);
    read(fd, buf, MAX_BUF);
    fprintf(stdout, "Received: %s\n", buf);
    close(fd);

    return 0;
}
