#include "monty.h"

/**
 * main - Entry point
 * @argc: size of argv
 * @argv: vector of arguments
 * Return: (0)
*/

int main(int argc, char **argv)
{
	FILE *filename = argc == 2 ? fopen(argv[1], "r") : NULL;
	size_t line_number = 0, length = 0, flag = 1;
	char *line = 0;
	stack_t *head = 0;

	if (!filename || argc != 2)
	{
		if (argc != 2)
			fprintf(stderr, "USAGE: monty file\n");
		else
			fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (flag && getline(&line, &length, filename) != -1)
	{
		line_number++;
		line = strtok(line, "\n");
		flag = execute_command(&head, line, line_number);
	}
	free_stack(&head);
	if (line)
		free(line);
	fclose(filename);
	if (flag)
		return (0);
	exit(EXIT_FAILURE);
}
