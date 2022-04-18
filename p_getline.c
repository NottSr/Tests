#include "main.h"

int main()
{
	char *line = NULL; /*create a var that will receive the line*/
	int status = 0; /*int with status for the fork*/
	pid_t pidC = 0; /*pidC for the return values*/
	size_t len = 0; /*lenght of the line*/
	ssize_t n_char = 0; /*var that will contain the # of char in line*/

	while(1)
	{
		printf("$ ");
        n_char = getline(&line, &len, stdin);

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
