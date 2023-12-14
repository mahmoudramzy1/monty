#include "monty.h"

/**
 * stack_push - it pushs the number into a node and insert it into the stack
 * @head: start of stack
 * @number: number goes into new created node
 * Return: 1 meaning no error 0 meaning error
*/

int stack_push(stack_t **head, int number)
{
	stack_t *mov = *head, *tmp = malloc(sizeof(stack_t));

	if (!tmp)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (0);
	}
	tmp->next = NULL;
	tmp->n = number;
	if (*head)
	{
		while (mov->next)
			mov = mov->next;
		tmp->prev = mov;
		mov->next = tmp;
	}
	else
	{
		tmp->prev = NULL;
		*head = tmp;
	}
	return (1);
}

/**
 * print_values - print values of the stack from the end to start
 * @head: start
 * Return: 1
*/

int print_values(stack_t *head)
{
	if (!head)
		return (1);
	print_values(head->next);
	fprintf(stdout, "%d\n", head->n);
	return (1);
}

/**
 * print_value - just prints the top value
 * @head: start
 * @line_number: line with command
 * Return: 1 or 0
*/

int print_value(stack_t *head, int line_number)
{
	if (head)
	{
		while (head->next)
			head = head->next;
		fprintf(stdout, "%d\n", head->n);
		return (1);
	}
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	return (0);
}

/**
 * free_stack - frees the stack
 * @head: start of stack
*/

void free_stack(stack_t **head)
{
	while (*head && (*head)->next)
	{
		*head = (*head)->next;
		free((*head)->prev);
	}
	if (*head)
		free(*head);
	*head = NULL;
}

/**
 * stack_pop - pops tha last element
 * @number: error detector
 * @head: start of stack
 * @line_number: number of line
 * Return: 1 if no error otherwise 0
*/

int stack_pop(stack_t **head, int *number, int line_number)
{
	stack_t *move = *head;

	if (*head)
	{
		while (move->next)
		{
			move = move->next;
		}
		*number = move->n;
		move->prev->next = NULL;
		free(move);
		return (1);
	}
	fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
	return (0);
}
