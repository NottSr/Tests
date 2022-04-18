#include "main.h"
#define UNUSED(x) (void)(x)

int main(int ac, char **av)
{
	int i = 0;
	UNUSED(ac);

	while (av[i])
	{
		printf("%s\n", av[i]);
		i++;
	}
	return(0);
}
