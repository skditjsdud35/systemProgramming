#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define BUFSIZE 512

int main(int arg, char **args){
	char buffer[BUFSIZE];

       	int fd_a, fd_b;
	ssize_t nread;
	long total = 0;

	if((fd_a = open(args[1], O_RDWR, S_IRUSR|S_IWUSR))==-1||(fd_b = open(args[2], O_RDWR|O_CREAT, S_IRUSR|S_IWUSR))==-1){
		perror("file open error");
		exit(1);
	 }

	while((nread= read(fd_a, buffer, BUFSIZE))>0){
		if((write(fd_b, buffer, nread))==-1){
	            perror("write");
		    exit(1);
		  }
	   }
	  write(fd_b, buffer, nread);
	  close(fd_a);
	  close(fd_b);

      return 0;
}
