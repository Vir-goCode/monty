#include "monty.h"

/**
 * monty_add - adds the top two elements of the stack.
 * @top_ptr: idk.
 * @line_n: idk.
 */
void monty_add(stack_t **top_ptr, unsigned int line_n)
{
	stack_t *last = *top_ptr;

	if (!last || !last->prev)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_n);
		free(ex.line);
		fclose(ex.fp);
		free_stack(*top_ptr);
		exit(EXIT_FAILURE);
	}
	last->prev->n += last->n;

	monty_pop(top_ptr, line_n);
}

/**
 * monty_sub - subtracts the top element
 * of the stack from the second top element of the stack.
 * @top_ptr: idk.
 * @line_n: idk.
 */
void monty_sub(stack_t **top_ptr, unsigned int line_n)
{
	stack_t *last = *top_ptr;

	if (!last || !last->prev)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_n);
		free(ex.line);
		fclose(ex.fp);
		free_stack(*top_ptr);
		exit(EXIT_FAILURE);
	}
	last->prev->n -= last->n;

	monty_pop(top_ptr, line_n);
}

/**
 * monty_div - divides the second top element of the stack
 * by the top element of the stack.
 * @top_ptr: idk.
 * @line_n: idk.
 */
void monty_div(stack_t **top_ptr, unsigned int line_n)
{
	stack_t *last = *top_ptr;

	if (!last || !last->prev)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_n);
		free(ex.line);
		fclose(ex.fp);
		free_stack(*top_ptr);
		exit(EXIT_FAILURE);
	}
	if (last->n != 0)
		last->prev->n /= last->n;
	else
	{
		fprintf(stderr, "L%u: division by zero\n", line_n);
		free(ex.line);
		fclose(ex.fp);
		free_stack(*top_ptr);
		exit(EXIT_FAILURE);
	}
	monty_pop(top_ptr, line_n);
}

/**
 * monty_mul - multiplies the second top element of the stack
 * with the top element of the stack.
 * @top_ptr: idk.
 * @line_n: idk.
 */
void monty_mul(stack_t **top_ptr, unsigned int line_n)
{
	stack_t *last = *top_ptr;

	if (!last || !last->prev)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_n);
		free(ex.line);
		fclose(ex.fp);
		free_stack(*top_ptr);
		exit(EXIT_FAILURE);
	}
	last->prev->n *= last->n;

	monty_pop(top_ptr, line_n);
}

/**
 * monty_mod - computes the rest of the division of the second top element
 * of the stack by the top element of the stack.
 * @top_ptr: idk.
 * @line_n: idk.
 */
void monty_mod(stack_t **top_ptr, unsigned int line_n)
{
	stack_t *last = *top_ptr;

	if (!last || !last->prev)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_n);
		free(ex.line);
		fclose(ex.fp);
		free_stack(*top_ptr);
		exit(EXIT_FAILURE);
	}
	if (last->n != 0)
		last->prev->n %= last->n;
	else
	{
		fprintf(stderr, "L%u: division by zero\n", line_n);
		free(ex.line);
		fclose(ex.fp);
		free_stack(*top_ptr);
		exit(EXIT_FAILURE);
	}

	monty_pop(top_ptr, line_n);
}