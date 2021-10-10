#include <stdlib.h>
#include <stdio.h>

static void my_exit1(void) {
	printf("first exit handler\n");
}

static void my_exit2(void) {
	printf("second exit handler\n");
}

void err_sys(const char *message)
{
	fputs(message, stderr);
	fputc('\n',stderr);
	exit(1);
}
