#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void	my_error(char *error, char *path)
{
	while (*error)
		write(2, error++, 1);
	if (path)
		while(*path)
			write(2, path++, 1);
	write(1, "\n", 1);
}

void	my_exec(char **argv, int i, char **envp)
{
	int	status;
	if (fork() == 0) {
		argv[i] = NULL;
		execve(argv[0], argv, envp);
		my_error("error: cannot execute ", argv[0]);
		exit(-1);
	}
	waitpid(-1, &status, 0);
	if (status == -1)
		exit(0);
}

void	do_pipe(char **argv, int i, char **envp)
{
	int end[2];

	pipe(end);
	if (!fork()) {
		close(end[0]);
		dup2(end[1], 1);
		close(end[1]);
		my_exec(argv, i, envp);
		exit(0); 
	} else {
		waitpid(-1, NULL, 0);
		dup2(end[0], 0);
		close(end[1]);
		close(end[0]);
	}
}

int main(int argc, char *argv[], char **envp)
{
	int	i;
	int stdin_cpy = dup(0);

	argc = 0;
	while (argv[0] && argv[1])
	{
		argv++;
		i = 0;
		while (argv[i] && strcmp(argv[i], ";") && strcmp(argv[i], "|"))
			i++;
		if (!(strcmp(*argv, "cd"))) {
			if (i != 2)
				my_error("error: cd: bad arguments", NULL);
			else if (chdir(argv[1]) != 0)
				my_error("error: cd: cannot change directory to ", argv[1]);
		}
		else if (i != 0 && (argv[i] == NULL || !(strcmp(argv[i], ";")))) {
			my_exec(argv, i, envp);
		}
		else if (i != 0 && !(strcmp(argv[i], "|"))) {
			do_pipe(argv, i, envp);
			argv += i + 1;
			i = 0;
			while (argv[i]) {
				if (!strcmp(argv[i], "|")) {
					do_pipe(argv, i, envp);
					argv += i + 1;
					i = 0;
				}
				if (argv[i] == NULL || !strcmp(argv[i], ";"))
					break ;
				i++;
			}
			my_exec(argv, i, envp);
			dup2(stdin_cpy, 0);
		}
		argv += i;
	}
	close(stdin_cpy);
	return 0;
}
