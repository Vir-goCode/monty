#include "monty.h"

extern_var_t ex;

/**
 * main - honestly, idk.
 * @argc: idk.
 * @argv: idk.
 * Return: less find out god.
 */
int main(int argc, char *argv[])
{
	FILE *fp;

	/* arg error */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	/* open file error */
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	read_file(fp);
	fclose(fp);
	return (0);
}

/**
 * read_file - honestly, idk.
 * @fp: idk.
 */
void read_file(FILE *fp)
{
	char *line = NULL;
	size_t len = 0;
	int i;
	stack_t *top_ptr = NULL;

	ex.fp = fp;

	/* get new line from fp's buffer */
	i = 1;
	while (getline(&line, &len, fp) != -1)
	{
		if (not_empty(line))
		{
			ex.data = clean_spaces(line);
			if (ex.data.value != NULL)
			{
				ex.int_value = atoi(ex.data.value);
			}
			ex.data.line_n = i;
			ex.line = line;
			execute_function(&top_ptr);
		}
		i++;
	}
	free(line);
	free_stack(top_ptr);
}

/**
 * execute_function - honestly, idk.
 * @stack: idk.
 * Return: less find out god.
 */
void execute_function(stack_t **stack)
{
	instruction_t functions[] = {
		{"push", monty_push}, {"pall", monty_pall}, {"pint", monty_pint},
		{"pop", monty_pop}, {"swap", monty_swap}, {"add", monty_add},
		{"sub", monty_sub}, {"nop", monty_nop}, {"div", monty_div},
		{"mul", monty_mul}, {"mod", monty_mod}, {"pchar", monty_pchar},
		{"pstr", monty_pstr}, {NULL, NULL}
	};
	int i;

	for (i = 0; functions[i].opcode; i++)
	{
		if (!strcmp(ex.data.op_func, functions[i].opcode))
		{
			functions[i].f(stack, ex.data.line_n);
			break;
		}
	}
	if (!functions[i].opcode)
	{

		fprintf(stderr, "L%d: unknown instruction", ex.data.line_n);
		fprintf(stderr, " %s\n", ex.data.op_func);
		free(ex.line);
		fclose(ex.fp);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}
/**
 * free_stack - honestly, idk.
 * @top_ptr: idk.
 * Return: less find out god.
 */
void free_stack(stack_t *top_ptr)
{
	stack_t *last;
	stack_t *prevNode;

	last = top_ptr;

	if (last)
	{
		prevNode = last->prev;

		while (prevNode)
		{
			free(last);
			last = prevNode;
			prevNode = prevNode->prev;
		}
		free(last);
	}
}