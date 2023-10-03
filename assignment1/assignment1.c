#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdio.h>
int main() {

	char *path="./sample.txt";
	int fd=0;
	char buffer[100]="";

	if((fd=open(path, O_RDWR|O_APPEND))==-1) perror("open1");

	if((lseek(fd, 14, SEEK_SET))==-1) perror("lseek1");
	if((read(fd, buffer, 8))==-1) perror("read1");
	printf("%s\n", buffer);
	close(fd);

	if((fd=open(path, O_RDWR))==-1) perror("open2");

	if((lseek(fd, 14, SEEK_SET))==-1) perror("lseek2");
	if((write(fd, "NTHU student.", 13))==-1) perror("write1");
	if((lseek(fd, 0, SEEK_SET))==-1) perror("lseek3");
	if((read(fd, buffer, 27))==-1) perror("read2");
	printf("%s\n", buffer);
	close(fd);

	return 0;
}
