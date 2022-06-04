#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void forkaddr(int x)
{
	if(fork() == 0)
		{
			printf("Child Address of x before: %p\n", &x);
			x = 20;
			printf("Child Address of x after: %p\n", &x);
			exit(0);
		}
}

int main()
{
	int x = 10;
	printf("Parent Address of x: %p\n", &x);
	
	forkaddr(x);	
	
	printf("Parent Address of x: %p\n", &x);
}

