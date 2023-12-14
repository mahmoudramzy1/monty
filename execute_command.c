#include "monty.h"

/**
 * IsInt - check if word consist of numbers only
 * @word: string
 * Return: 1 --> numbers only 0 otherwise
*/

int IsInt(char *word)
{
	int index = 0;

	if (word[index] == '-' || word[index] == '+')
		index++;
	while ('0' <= word[index] && word[index] <= '9')
	{
		index++;
		if (!word[index])
			return (1);
	}
	return (0);
}

/**
 * execute_command - check if line has a command in it
 * @head: start of stack
 * @line: string of words
 * @line_number: number of line
 * Return: 1 or 0
*/

int execute_command(stack_t **head, char *line, int line_number)
{
	int index = 0;
	char *word = 0;

	while (line[index] == ' ')
		index++;
	if (line[index] == 0)
		return (1);
	word = strtok(line, " \0");
	if (strcmp(word, "push") == 0)
	{
		word = strtok(NULL, " \0");
		if (word && IsInt(word))
			return (stack_push(head, atoi(word)));
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		return (0);
	}
	else if (strcmp(word, "pall") == 0)
		return (print_values(*head));
	else if (strcmp(word, "pint") == 0)
		return (print_value(*head, line_number));
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, word);
	return (0);
}
