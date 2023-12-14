#include "monty.h"

/**
 * stack_swap - swaps two last elements
 * @head: start of the stack
 * @line_number: number of line
 * Return: 1 if no error 0 if error
*/

int stack_swap(stack_t **head, int line_number)
{
	int n, n1;

	if (*head && (*head)->next)
	{
		stack_pop(head, &n, line_number);
		stack_pop(head, &n1, line_number);
		stack_push(head, n1);
		stack_push(head, n);
		return (1);
	}
	fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
	return (0);
}

/**
 * stack_add - adds two last elements
 * @head: start of the stack
 * @line_number: number of line
 * Return: 1 if no error 0 if error
*/

int stack_add(stack_t **head, int line_number)
{
	int n = 0, n1 = 0;

	if (*head && (*head)->next)
	{
		stack_pop(head, &n, line_number);
		stack_pop(head, &n1, line_number);
		stack_push(head, n1 + n);
		return (1);
	}
	fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
	return (0);
}


/**
 * stack_sub - adds two last elements
 * @head: start of the stack
 * @line_number: number of line
 * Return: 1 if no error 0 if error
*/

int stack_sub(stack_t **head, int line_number)
{
	int n, n1;

	if (*head && (*head)->next)
	{
		stack_pop(head, &n, line_number);
		stack_pop(head, &n1, line_number);
		stack_push(head, n - n1);
		return (1);
	}
	fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
	return (0);
}