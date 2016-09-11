#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int fd;
    char *fifoLoc = "/tmp/ipc_fifo";

    mkfifo(fifoLoc, 0666);

    fd = open(fifoLoc, O_WRONLY);
    write(fd, "Test", sizeof("Test"));
    close(fd);

    unlink(fifoLoc);

    return 0;
}
