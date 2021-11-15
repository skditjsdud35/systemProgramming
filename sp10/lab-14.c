#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
	FILE *fp;
	char buf[BUFSIZ];

	fp = popen("who | sort", "w");
	if(fp != NULL) {
		fwrite(buf, sizeof(buf), strlen(buf), fp);
		pclose(fp);
		exit(0);
	}
	exit(1);
}
