#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - a UNIX command line interpreter.
 * When this program is compiled and exeecuted, creates a child process
 * and runs the getline system call and reads the input from stdin.
 * This input should be the path to an executable.
 * Return: Always 0.
 */

int main(int argc, char *argv[], char **envir)
{
	char *buffer = NULL, *prompter = "$ ";
	char **args;
	size_t no_of_args, buffer_size = 0;
	ssize_t content;
	pid_t wpid;
	int wstatus;
	bool from_pipe = false;
	struct stat startbuffer;

	while (1 && !from_pipe)
	{
		/* Check if data is piped into program or entered from terminal */
		if (isatty(STDIN_FILENO) == 0)
			from_pipe = true;

		/* Print the prompter sign `$ ` on the terminal */
		write(STDOUT_FILENO, prompter, 2);

		/* Read data from standard input */
		content = getline(&buffer, &buffer_size, stdin);
		if (content == -1)
		{
			perror("Error (getline)");
			free(buffer); /* If getline fails, free memory */
			exit(EXIT_FAILURE);
		}

		/* Replace the newline character with a null terminator */
		if (buffer[content - 1] == '\n')
			buffer[content - 1] = '\0';

		args = split_string(buffer, " ", &no_of_args);

		/* Check if executable exists */
		if (!check_file_status(args[0], &startbuffer))
		{
			perror("Error (file status)");
			continue;
		}

		/* Create a child process and use it to execute the command */
		wpid = fork();
		if (wpid == -1) /* If fork fails */
		{
			perror("Error (fork)");
			exit(EXIT_FAILURE);
		}
		if (wpid == 0) /* Child process */
			execute(args, no_of_args, envir);

		/* Parent process should wait for the child process to finish */
		if (waitpid(wpid, &wstatus, 0) == -1)
		{
			perror("Error (wait)");
			exit(EXIT_FAILURE);
		}
	}

	free(buffer);
	return (0);
}

int execute(char **arguments, int no_of_args, char **envirp)
{
	execve(arguments[0], arguments, envirp);

	/* If execve failed */
	free_vector(arguments, no_of_args);
	perror("Error (execve)"); 
	exit(EXIT_FAILURE);
}

void handle_error(pid_t pid)
{
	if (pid == -1)
	{
		printf("Error");
		exit(EXIT_FAILURE);
	}
}
