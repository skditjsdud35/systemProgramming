#include <sys/types.h>
#include "ourhdr.h"

int glob = 6;

int main(void) {
	int var;
	pid_t pid;

	var = 88;
	printf("before fork\n");

	if((pid = fork()) < 0)
		perror("fork error");
	else if (pid == 0) {
		glob++;
		var++;
		_exit(0);
	}

	printf("pid = %d, glob = %d, var = %d\n", getpid(), glob, var);
	exit(0);
}
