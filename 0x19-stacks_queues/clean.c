#include "monty.h"

/**
 * not_empty - honestly, idk.
 * @line: idk.
 * Return: 0 if it's empty, 1 if it's not empty..
 */
size_t not_empty(char *line)
{
	size_t i;

	for (i = 0; i < strlen(line); i++)
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			break;
	}
	if (i == strlen(line) || line[i] == '#')
		return (0); /* empty */
	return (1); /* not empty */
}

/**
 * clean_spaces - honestly, idk.
 * @line: idk.
 * Return: data struct.
 */
content_v clean_spaces(char *line)
{
	content_v data;
	char *token;
	size_t i;

	data.op_func = NULL;
	data.value = NULL;
	token = strtok(line, " \n\t");
	while (token != NULL)
	{
		if (strcmp(token, ""))
		{
			data.op_func = token;
			break;
		}
		token = strtok(NULL, " \n\t");
	}
	if (token == NULL)
		return (data);

	token = strtok(NULL, " \n\t");
	while (token != NULL)
	{
		if (strcmp(token, ""))
		{
			for (i = 0; i < strlen(token); i++)
			{
				if (!(token[i] >= '0' && token[i] <= '9'))
					if (token[0] != '-')
						break;
			}
			if (i == strlen(token))
			{
				if (!strcmp(token, "-0"))
					data.value = 0;
				data.value = token;
			}
		}
		token = strtok(NULL, " \n\t");
	}
	return (data);
}