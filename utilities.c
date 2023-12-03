#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int					sign;
	unsigned long long	result;
	unsigned long long	max;

	result = 0;
	sign = 1;
	max = 9223372036854775807;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		if (result > max && sign == 1)
			return (-1);
		if (result > max && sign == -1)
			return (0);
		str++;
	}
	return (result * sign);
}

void	error_ms(void)
{
	ft_printf("Unexpected error, Wrong process ID");
	exit(0);
}

int	ft_isnum(char *str)
{
	if (str == NULL || *str == '\0')
		return (0);
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}
