#include "minitalk.h"

void	sent_c_to_bin_signals(char c, int pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & 128)
		{
			if (kill(pid, SIGUSR2) == -1)
				error_ms();
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				error_ms();
		}
		c <<= 1;
		bit++;
		pause();
		usleep(100);
	}
}

void	sent_string(char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i])
		sent_c_to_bin_signals(str[i++], pid);
	sent_c_to_bin_signals('\0', pid);
}

void	recieved(int sig)
{
	static int	sent;

	if (sig == SIGUSR1)
	{
		ft_printf("%d BIT signal sent successfully!\n", ++sent);
		exit(0);
	}
	if (sig == SIGUSR2)
		++sent;
}

int	main(int argc, char *argv[])
{
	int		pid;
	int		client_pid;

	client_pid = getpid();
	if (argc == 3 && ft_isnum(argv[1]))
	{
		signal(SIGUSR1, recieved);
		signal(SIGUSR2, recieved);
		pid = ft_atoi(argv[1]);
		if (kill(pid, 0) != 0)
			error_ms();
		ft_printf("Text currently sending.. \n");
		sent_string(argv[2], pid);
	}
	else
	{
		ft_printf("Your input should be 3 args like this :\n");
		ft_printf("(./client) (server_pid_number) ('Your message')");
	}
	return (0);
}
