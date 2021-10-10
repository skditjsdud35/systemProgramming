#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PATH_MAX 1024
int main(){
	char *var = "PATH";
	char *value, *getc;
	char path[PATH_MAX];

	value = getenv(var);
	printf("not changed PATH :\n%s\n",value);
	unsetenv(var);
	value = getenv(var);
	printf("after delete PATH : \n%s\n",value);
	getc = getcwd(path,PATH_MAX);

	if(getc==NULL)
		perror("error getcwd");
	else
		printf("lab07's directory: %s\n", path);
		
	printf("==============================================\n");
	printf("          now changing PATH's value           \n");
	printf("==============================================\n");

	if(setenv(var,path,1)==-1)
		perror("error setenv");
		
	value = getenv(var);
	printf("now PATH : %s\n",  value);
		
	return 0;
}
