#include "main.h"

int main(int ac, char **argv)
{
	char *prompt = "(Kshell) $ ";
	char *lineptr= NULL;

	char *lineptr_copy = NULL;
	const char *delim = " \n";

	size_t n = 0;
	ssize_t nchars_read;

	int num_tokens = 0;
	char *token;
	int i;
	
	/*declaring the variables*/
	(void)ac;

	/*adding an infinte loop to keep showing prompt after every execution*/

	while(1)
	{
		printf("%s", prompt);
		nchars_read = getline(&lineptr, &n, stdin);

		/*check if getline function failed or read EOF or use to use CRT+D*/

		if (nchars_read == -1)
		{
			printf("Exiting shell....\n");
			return (-1);
		}

		/*allocation of space for copy and lineptr*/
		lineptr_copy = malloc(sizeof(char) * nchars_read);

		if (lineptr_copy== NULL)
		{
			perror("tsh: memory allocation error");
			return (-1);
		}

		/*copy lineptr to lineptr_copy*/

		strcpy(lineptr_copy, lineptr);

		/**
		 * split the strins(lineptr) into an array of the word
		 *
		 * calculate the total number of tokens
		 */

		token = strtok(lineptr, delim);

		while (token != NULL)
		{
			num_tokens++;

			token = strtok(NULL, delim);
		}

		num_tokens++;

		/*Allocate space to hold the array of strings*/

		argv = malloc(sizeof(char *) *num_tokens);

		/*store token in the argv array*/

		token = strtok(lineptr_copy, delim);

		for (i = 0; token != NULL; i++)
		{
			 argv[i] = malloc(sizeof(char) * strlen(token));
			 strcpy(argv[i], token);

			 token = strtok(NULL, delim);
		}
		argv[i] = NULL;

		/*execute the command*/
		execmd(argv);
	}

	/*free up allocated memory*/

	free(lineptr_copy);

	free(lineptr);


	return (0);
}
