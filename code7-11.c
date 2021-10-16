#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
	int pid;
	int status;
	pid = fork();
	if (pid < 0) {
		perror("fork error: ");
		exit(0);
	}
	if(pid == 0) {
		printf("I am Child\n");
		sleep(2);
		return 2;
	}
	else {
		printf("Parent: wait (%d)\n", pid);
		waitpid(pid, &status, 0);
		if(WIFEXITED(status)){
			printf("정상종료\n");
			printf("리턴값 %d\n", WEXITSTATUS(status));
		}
		else if (WIFSIGNALED(status)){
			printf("신호받았음\n");
			printf("신호번호 %d\n", WTERMSIG(status));
		}
	}
	exit(0);
}

