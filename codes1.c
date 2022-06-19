#include "monty.h"

/**
 * op_push - pushes an element to the stack
 * @stack: pointer to the pointer to the first element in stack
 * @line_number: line number of the instruction
 */
void op_push(stack_t **stack, unsigned int line_number)
{
	int num;
	stack_t *new;

	if (is_valid_int(op.arg) == 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_op();
		exit(EXIT_FAILURE);
	}
	num = atoi(op.arg);

	/* add num to beginning of stack */
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failedr\n");
		free_op();
		exit(EXIT_FAILURE);
	}

	new->n = num;
	new->prev = NULL;
	new->next = *stack;

	if (*stack)
		(*stack)->prev = new;

	*stack = new;
}
