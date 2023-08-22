#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
	pid_t process_pid;
	pid_t parent_ppid;

	parent_ppid = getppid();
	process_pid = getpid();

	printf("my parent porcess id %u\n", parent_ppid);

	printf("my process is %u\n", process_pid);
	return (0);
}
