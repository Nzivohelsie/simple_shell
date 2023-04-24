#include "main.h"

void exit(**argv)
{
	if (strcmp(argv[0], "exit") == 0)
	{
		printf("exiting...\n");

		exit(0);
	}
