#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFSIZE 1024

int main() {
	int fd, i;
	char buf[BUFSIZE];
	char* myfifo = "./fifo";

    mkfifo(myfifo, 0666);

	if((fd = open(myfifo, O_RDWR)) != -1) {
		for(i = 0; i < 3; i++) {
			if(read(fd, buf, BUFSIZE) > 0) {
				write(1, buf, strlen(buf));
			}
		}
	}
	close(fd);
	
	return 0;
}
