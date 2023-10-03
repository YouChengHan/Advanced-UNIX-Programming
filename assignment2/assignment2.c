#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdio.h>
int main(int argc, char *argv[]) {

	char *path_src=argv[1], *path_dst=argv[2];
	int fd_src=0, fd_dst=0, size=0;
	char buffer[1000]="";

	if((fd_src=open(path_src, O_RDONLY))==-1) perror("open src");
	if((fd_dst=open(path_dst, O_RDWR|O_CREAT|O_TRUNC, 0644))==-1) perror("open dst");

	if((lseek(fd_src, 0, SEEK_SET))==-1) perror("lseek src");
	if((lseek(fd_dst, 0, SEEK_SET))==-1) perror("lseek dst");

	// need to call read and write in a loop to copy
	// or the redundant copied buffer will contain other characters
	// which cause diff command detects different bytes.
	while((size=read(fd_src, buffer, sizeof(buffer)))>0)
		write(fd_dst, buffer, size);

	close(fd_src);
	close(fd_dst);
	return 0;
}
