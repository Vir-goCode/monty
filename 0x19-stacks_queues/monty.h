#ifndef MONTY
#define MONTY

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct content  - opcode and its function
 * @op_func: the opcode
 * @value: function to handle the opcode
 * @line_n: number of the line
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct content
{
	char *op_func;
	char *value;
	int line_n;
} content_v;

/**
 * struct stakit  - opcode and its function
 * @int_value: idk.
 * @data: idk.
 * @fp: idk.
 * @line: idk.
 * Description: honestly, idk.
 */
typedef struct stakit
{
	int int_value;
	content_v data;
	FILE *fp;
	char *line;
} extern_var_t;
extern extern_var_t ex;

int main(int argc, char *argv[]);
void read_file(FILE *fp);
void execute_function(stack_t **stack);
size_t not_empty(char *line);
content_v clean_spaces(char *line);

void monty_push(stack_t **top, unsigned int line_n);
void monty_pall(stack_t **top, unsigned int line_n);
void monty_pint(stack_t **top, unsigned int line_n);
void monty_pop(stack_t **top, unsigned int line_n);
void monty_swap(stack_t **top, unsigned int line_n);
void monty_add(stack_t **top, unsigned int line_n);
void monty_sub(stack_t **top_ptr, unsigned int line_n);
void monty_mul(stack_t **top_ptr, unsigned int line_n);
void monty_nop(stack_t **top_ptr, unsigned int line_n);
void monty_div(stack_t **top_ptr, unsigned int line_n);
void monty_mod(stack_t **top_ptr, unsigned int line_n);
void monty_pchar(stack_t **top_ptr, unsigned int line_n);
void monty_pstr(stack_t **top_ptr, unsigned int line_n);

void free_stack(stack_t *top_ptr);
#endif