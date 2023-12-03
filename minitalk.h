#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stddef.h>
# include "ft_printf/ft_printf.h"

int		ft_atoi(const char *str);
void	error_ms(void);
int		ft_isnum(char *str);

#endif