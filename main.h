#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

char **_strtok(char *str);
void _execve(char **av);
char *_path(char *command);
int _environ(void);

#endif
