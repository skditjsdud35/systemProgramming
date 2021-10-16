#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <error.h>
#include <sys/stat.h>

#define BUFSIZE 512

int main(int argc, char *argv[]){
	int length;
	int fd1, fd2;
	char buf[BUFSIZE];
	int chk = 0;
	int pid;
	memset(buf,0,512);

	if((fd1 = open("./sample.txt",O_RDONLY))==-1){
		perror("open");
		exit(1);
	}
	if((fd2 = open("./output.txt", O_WRONLY|O_CREAT,0644))==-1){
		perror("output_open");
		exit(1);
	}
	if(read(fd1, buf, BUFSIZE)==-1){
		perror("read");
		exit(1);
	}
	length = strlen(buf);

	printf("length : %d\n", length-1);
	printf("--------------------------\n");
	while(chk < length-1){
		pid = vfork();
		if(pid==-1){
			perror("fork\n");
			exit(1);
		}
		else if(pid==0){
			printf("child : %ld\n", (long)getpid());
			chk++;
			if((write(fd2,buf,chk))==-1){
				perror("write");
				exit(1);
			}
			if((write(fd2, "\n", 1))==-1){
				perror("write");
				exit(1);
			}
		}
		else{
			printf("parents pid  : %ld\n", (long)getpid());
		}
	}
	close(fd1);
	close(fd2);
	return 0;
}
