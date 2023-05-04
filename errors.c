#include "shell.h"

/**
 * print_error - prints error messages to standard error
 * @vars: pointer to struct of variables
 * @msg: message to print out
 *
 * Return: void
 */
void print_error(vars_t *vars, char *msg)
{
	char *count;

	_puts2(vars->argv[0]);
	_puts2(": ");
	count = _uitoa(vars->count);
	_puts2(count);
	free(count);
	_puts2(": ");
	_puts2(vars->av[0]);
	if (msg)
	{
		_puts2(msg);
	}
	else
		perror("");
}

/**
 * _puts2 - prints a string to standard error
 * @str: string to print
 *
 * Return: void
 */
void _puts2(char *str)
{
	ssize_t num, len;

	num = _strlen(str);
	len = write(STDERR_FILENO, str, num);
	if (len != num)
	{
		perror("Fatal Error");
		exit(1);
	}

}

/**
 * _uitoa - converts an unsigned int to a string
 * @count: unsigned int to convert
 *
 * Return: pointer to the converted string
 */
char *_uitoa(unsigned int count)
{
	char *str;
	unsigned int tmp, i;

	tmp = count;
	for (i = 0; tmp != 0; i++)
		tmp /= 10;
	str = malloc(sizeof(char) * (i + 1));
	if (str == NULL)
	{
		perror("Malloc Error1");
		exit(127);
	}
	str[i] = '\0';
	for (--i; count; --i)
	{
		str[i] = (count % 10) + '0';
		count /= 10;
	}
	return (str);
}
