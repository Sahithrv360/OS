#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main()
{
    int fd;
    char buf[20];

    // open()
    fd = open("file.txt", O_CREAT | O_RDWR, 0644);
    printf("File Descriptor = %d\n", fd);

    // write()
    write(fd, "Hello", 5);

    // lseek()
    lseek(fd, 0, SEEK_SET);

    // read()
    read(fd, buf, 5);
    buf[5] = '\0';
    printf("Data Read = %s\n", buf);

    // close()
    close(fd);
    printf("File Closed\n");

    // stat()
    struct stat s;
    stat("file.txt", &s);
    printf("File Size = %ld bytes\n", s.st_size);

    // sync()
    sync();
    printf("Data Synced\n");

    return 0;
}

