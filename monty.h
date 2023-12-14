#ifndef MONTY_H
#define MONTY_H

#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

int stack_push(stack_t **head, int number);
int print_values(stack_t *head);
int print_value(stack_t *head, int line_number);
void free_stack(stack_t **head);
int IsInt(char *word);
int execute_command(stack_t **head, char *line, int line_number);
int stack_pop(stack_t **head, int *number, int line_number);
int stack_swap(stack_t **head, int line_number);
int stack_add(stack_t **head, int line_number);
int stack_sub(stack_t **head, int line_number);
int stack_div(stack_t **head, int line_number);
int stack_mul(stack_t **head, int line_number);

#endif
