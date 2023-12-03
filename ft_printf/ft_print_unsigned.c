#include "ft_printf.h"

void	putnbr(unsigned int n)
{
	if (n > 9)
		putnbr(n / 10);
	ft_print_char(n % 10 + '0');
}

int	ft_print_unsigned(unsigned int n)
{
	unsigned int	count;

	count = 0;
	putnbr(n);
	if (n == 0)
		count++;
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}
