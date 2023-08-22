#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char *shell_man = NULL;
	ssize_t size = 0;
	ssize_t get_return;
	char *temp;

	get_return = getline(&shell_man, &size, stdin);

	if (get_return == -1)
	{
		free(shell_man);
		exit(0);
	}

	printf("before tokenizing\n");
	printf("you entered %s", shell_man);

	printf("after tokenizing\n");

	temp = strtok(shell_man, "\n");

	printf("you entered %s", temp);

	free(shell_man);

	return (0);
}
