#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
/**
 * main - print ppid
 * Return: 0
 */
int main(void)
{
	int i = 9;
	int j = 6;
	pid_t ppid;
	int sum = i + j;

	printf("sum is %d\n", sum);
	ppid = getppid();
	printf("ppid is %u\n", ppid);

	return (0);
}
