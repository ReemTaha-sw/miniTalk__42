#include "ft_printf.h"

int	ft_print_string(char *c)
{
	int	count;

	count = 0;
	if (!c)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (c[count])
	{
		write(1, &c[count], 1);
		count++;
	}
	return (count);
}
