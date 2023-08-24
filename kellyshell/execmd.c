#include "main.h"

void execmd(char **argv)
{
	char *command = NULL;
	char *actual_command = NULL;

	if(argv)
	{
		/* get the command */
		command = argv[0];

		/* execute the command with execve */

		actual_command = get_location(command);

		if (execve(actual_command, argv, NULL) == -1)
		{
			perror("Error:");
		}
	}

}
