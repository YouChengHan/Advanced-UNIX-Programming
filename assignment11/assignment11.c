#include <stdio.h>
#include <unistd.h>
#include <syslog.h>

extern void daemonize(const char *cmd);

int main() {

	// daemonize
	char *cmd="assignment11d";
	daemonize(cmd);

	// need to use absolute path since the working directory has been set to root. (detached)
	FILE *fp=fopen("/home/kevin/UNIX/assignment11/assignment11.txt", "w");
	char *name=getlogin();
	fprintf(fp, "Login name: %s\n", name);
	//syslog(LOG_NOTICE, "Login name: %s\n", name);
	//closelog();

	fclose(fp);
	return 0;
}