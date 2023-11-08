#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int main() {

	pid_t pid;

	if((pid=fork())<0) perror("fork error");
	// child process
	else if(pid==0) exit(0);

	// Parent process
	// Zombie process is caused by not handling exit status from child process
	
	// Using system() will create a shell to execute the command, 
	// hence ps -l will show a sh process additionally.
	// Using exec() directly will replace the calling process with the command, 
	// so the assignment6 process will be replaced as ps process.
	else system("ps -l"); //execlp("ps", "ps", "-l", NULL);

	return 0;
}
