#include "shell.h"

/**
 * main - Check the code..
 *
 * Return:the shell command..
 * Description
 * @argc:argument count.
 * @argv:argument vector
 * @env:environment
 */

int main(int argc, char **argv, char **env)
{
char *lineptr = NULL;
char *tok[10], *del = " ";
int wstatus, j, k, fd = 1;
size_t n = 0;
pid_t pid;

 /* declaring void variables */
(void)argc;
(void)argv;

while (true)
{
if (isatty(0))
write(fd, "#cisfun$ ", 9);
if (getline(&lineptr, &n, stdin) == -1)
{
free(lineptr);
exit(0);
}
k = 0;
while (lineptr[k])
{
if (lineptr[k] == '\n')
lineptr[k] = 0;
k++;
}
j = 0;
tok[j] = strtok(lineptr, del);
while (tok[j])
{
tok[++j] = strtok(NULL, del);
}
pid = fork();
if (pid < 0)
{
write(1, "Fork Failed\n", 12);
free(lineptr);
return (-1);
}
else if (pid == 0)
{
if (execve(tok[0], tok, env) == -1)
write(1, "Command Not Found\n", 19);
}
else
wait(&wstatus);
}
free(lineptr);
return (0);

}

