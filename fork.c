#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
	pid_t forkRV;

	printf("Before calling fork function\n");

	forkRV = fork();

	if(forkRV == -1)
	{
		perror("precess creation failed\n");
		return (-1);
	}

	if(forkRV == 0)
	{
		printf("I am in the child process\n");

		printf("child pid is %u\n", getpid());
		printf("PPID of the cuild is %u\n", getppid());
	}
	else{
	printf("I am the parent\n");

	printf("my child pid is  %u\n", forkRV);
	}




	return(0);

}
