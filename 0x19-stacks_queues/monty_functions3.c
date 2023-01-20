#include "monty.h"

/**
 * monty_nop - nothing to do here.
 * @top_ptr: idk.
 * @line_n: idk.
 */
void monty_nop(stack_t **top_ptr, unsigned int line_n)
{
	*top_ptr = *top_ptr;
	line_n = line_n;
}

/**
 * monty_pchar - prints the value at the top of the stack,
 * followed by a new line.
 * @top_ptr: idk.
 * @line_n: idk.
 */
void monty_pchar(stack_t **top_ptr, unsigned int line_n)
{
	if (!(*top_ptr))
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_n);
		free(ex.line);
		fclose(ex.fp);
		free_stack(*top_ptr);
		exit(EXIT_FAILURE);
	}
	if (isascii((*top_ptr)->n))
		printf("%c\n", (char)((*top_ptr)->n));
	else
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_n);
		free(ex.line);
		fclose(ex.fp);
		free_stack(*top_ptr);
		exit(EXIT_FAILURE);
	}
}

/**
 * monty_pstr - prints the value at the top of the stack,
 * followed by a new line.
 * @top_ptr: idk.
 * @line_n: idk.
 */
void monty_pstr(stack_t **top_ptr, unsigned int line_n)
{
	stack_t *aux = *top_ptr;

	(void)line_n;

	if (!top_ptr || !(*top_ptr))
	{
		putchar(10);
		return;
	}
	while (aux)
	{
		if (isascii(aux->n) && aux->n != 0)
		{
			printf("%c", (char)(aux->n));
		}
		else
			break;
		aux = aux->prev;
	}
	putchar(10);
}