#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
int main() {

	pid_t pid;

	if((pid=fork())<0) perror("fork error");
	else if(pid==0) {
		// create a new session
		if(setsid()==-1) {
			perror("setsid");
			return 1;
		} 
		// Although the child process is set to be in another session,
		// the standard output of child process still points to 
		// the terminal unless it has been specified explicitly.
		char cmd[100]="";
		sprintf(cmd, "ps -p %d -o pid,pgid,tpgid", getpid());
		system(cmd);
	}
	// wait the child process
	else wait(NULL);

	return 0;
}
