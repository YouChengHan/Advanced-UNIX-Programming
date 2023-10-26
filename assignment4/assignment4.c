#include <stdio.h>
#include <time.h>

int main() {
	time_t raw_time;
	struct tm *time_info;
	char buf[100];

	time(&raw_time);
	time_info=localtime(&raw_time);

	strftime(buf, 100, "%a %b %d %H:%M:%S %Z %Y", time_info);
	printf("%s\n", buf);

	return 0;
}
