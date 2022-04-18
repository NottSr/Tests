#include "main.h"
#define UNUSED(x) (void)(x)

int main()
{
	char *line = NULL; /*create a var that will receive the line*/
	char *delim = " ", *token;
	int cap = 8, lent = 0;
	char **tokens = malloc(cap * sizeof(char *));
	int status = 0; /*int with status for the fork*/
	pid_t pidC = 0; /*pidC for the return values*/
	size_t lenl = 0; /*lenght of the line*/
	ssize_t n_char = 0; /*var that will contain the # of char in line*/

	while(1)
	{
		printf("$ ");
		n_char = getline(&line, &lenl, stdin);

		token = strtok(line, delim);
		while (token)
		{
			tokens[lent] = token;
			lent++;

			if(lent >= cap)
			{
				cap = (int) (cap * 1.5);
				tokens = realloc(tokens, cap * sizeof(char *));
			}
			token = strtok(NULL, delim);
		}
		tokens[lent] = NULL;

		pidC = fork();
		if(pidC > 0)
		{
			wait(&status);
		}
		else if(pidC == 0)
		{
			fwrite(line, n_char, 1, stdout);
			exit(0);
			free(line);
		}
	}
	exit(EXIT_SUCCESS);
}
