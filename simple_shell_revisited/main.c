#include "main.h"

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 when success or 1 on error
 */
int main(int argc, char **argv)

{
	info_t info[] = {_INIT_}; // array of struct which gets updated.
	int fd = 2;

	/* asm("mov %1, %0\n\t"
		"add $3, %0"
		: "=r"(fd)
		: "r"(fd)); */
	if (argc == 2) // opens the file when the command is piped into executable
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_puts(argv[0]);
				_puts(": 0: Can't open ");
				_puts(argv[1]);
				_putchar('\n');
				_putchar(BUFFER_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = fd; // assigns the file discriptor to the readfd member of the shell struct object.
	}
	create_env_list(info); // takes the info struct as an argument and creates a linked list on environment variables
	rd_history(info);	   // reads the history of commands from the history file.
	hsh(info, argv);

	return (EXIT_SUCCESS);
}
/* The reason echo "ls" | ./hsh works is because the executable recieves "ls" as a standard input from echo, and can process the input because it is recieving it through standard input.
Now, the reason ./hsh ls will not work is because ./hsh is not recieving it as an input, it treats ls as a command to be executed, in this case the shell attempts to locate and execute the ls command rather than passing it as input into ./hsh, moreso, you cannot directly use the open system call on command lihe ls because ls is not a file or a string that represent a file. Instead, ls is typically a separate executable program that you execute, not a file you open*/