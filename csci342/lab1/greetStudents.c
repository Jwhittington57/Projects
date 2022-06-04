#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>
#define N 2
int main()

{
	char *arr[] = { "kevin", "jordan", "Josh" };
	/*
	printf("paraent finished");
	return 0;
	*/

	int status, i;
	pid_t pid;

	//parent creates N children
			
	int j;
	
	for(j=0; j<3; j++)
	{
		printf("%s\n",arr[j]);
	
		if((pid = fork()) == 0){ //child
		char *args[]={"./EXEC","ls", NULL};
                execv(args[0],args);
			
		exit(100+i);
	}
	}
	while ((pid = waitpid(-1, &status, 0)) > 0)
		{
		if(WIFEXITED(status))
			printf("child %d terminated normally with exit status=%d\n",
				pid,WEXITSTATUS(status));
		else
			printf("child %d terminated abnormally\n", pid);
		}
		printf("parent finished\n");
		//the only normal termination is if there are no more children
		if(errno != ECHILD)
			printf("waitpid error");

		exit(0);	



}
