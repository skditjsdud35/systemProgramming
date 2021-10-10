#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char *var, *value;
	if(argc == 1 || argc > 3) {
		fprintf(stderr,"usage: environ var [value]\n");
		exit(1);
	}
}
