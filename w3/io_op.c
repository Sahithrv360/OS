#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/ioctl.h>
#include<sys/stat.h>
#define WR_VALUE _IOW('a','a',char* )

int main(){
	int fd = open("sample.txt",O_RDONLY | O_CREAT,0644);
	int fd2 = open("f2.txt",O_WRONLY | O_CREAT | O_TRUNC , 0644);
	int fd3 = open("f3.txt",O_RDWR);

	char c[20];
	read(fd,&c,20); // read from sample then print it
	printf("Text in file is : \n %s\n",c);
	write(fd2,c,read(fd,&c,20)); // write from sample to f2
	lseek(fd3,5,SEEK_CUR);
	char c1[20];
	read(fd3,&c1,20);
	printf("Text in f3 after 5 char is : \n %s \n",c1);
	char str[100];
	printf("Enter text to enter in a file : ");
	fgets(str,sizeof(str),stdin);
	ioctl(fd3,WR_VALUE,(char *)&str);
	struct stat sfile;
	stat("systemcall.c",&sfile);
	printf("st_mode = %o \n ",sfile.st_mode);
	close(fd);
	close(fd2);
	close(fd3);
	return 0;
}
