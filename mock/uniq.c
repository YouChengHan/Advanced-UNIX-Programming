#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(int argc, char *argv[]) {

	int iflag=0, uflag=0, cflag=0;
	FILE *fp;
	char buf[1024]="", org[1024]="", src[1024]="", dst[1024]="";
	int cnt=1;

	if(argc<2) {
		printf("file name required.\n");
		return 1;
	}

	for(int i=1; i<argc; ++i) {
		if(argv[i][0]!='-') {
			fp=fopen(argv[i], "r");
			if(fp==NULL) perror("fopen");
		}
		else {
			if(argv[i][1]!='c'&&argv[i][1]!='u'&&argv[i][1]!='i') {
				printf("unknown arguments.\n");
				return 1;
			}
			if(argv[i][1]=='c') cflag=1;
			if(argv[i][1]=='u') uflag=1;
			if(argv[i][1]=='i') iflag=1;

		}
	}

	fgets(buf, 1024, fp);
	strcpy(org, buf);
	while(fgets(buf, 1024, fp)) {
		if(iflag) {
			char tmp[1024]="";
			strcpy(tmp, org);
			for(int i=0; i<strlen(org); ++i) tmp[i]=tolower(org[i]);
			strcpy(src, tmp);
			strcpy(tmp, buf);
			for(int i=0; i<strlen(buf); ++i) tmp[i]=tolower(buf[i]);
			strcpy(dst, tmp);
		}
		else {
			strcpy(src, org);
			strcpy(dst, buf);
		}
		if(!strcmp(src, dst)) {
			++cnt;
			continue;
		}
		else {
			if(!(uflag&&cnt>1)) {
				if(cflag) printf("%d ", cnt);
				printf("%s", org);
			}
			strcpy(org, buf);
			cnt=1;
		}
	}
	if(!(uflag&&cnt>1)) {
		if(cflag) printf("%d ", cnt);
		printf("%s", org);
	}

	fclose(fp);
	return 0;
}
