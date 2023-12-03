#include "minitalk.h"

void	print_char(char *c, int *received, int *client_pid, int *bit)
{
	ft_printf("%c", *c);
	if (*c == '\0')
	{
		ft_printf("\n%d BITs signal recieved from client PID: %d\n",
			*received, *client_pid);
		*received = 0;
		*c = 0;
		if (kill(*client_pid, SIGUSR1) == -1)
			error_ms();
		return ;
	}
	*bit = 0;
}

void	set_client_pid(int client_pid, siginfo_t *info)
{
	if (!client_pid)
		client_pid = info->si_pid;
}

void	action(int sig, siginfo_t *info, void *context)
{
	static int	client_pid;
	static int	bit;
	static char	c;
	static int	received;
	static int	current_pid;

	(void)context;
	set_client_pid(client_pid, info);
	current_pid = info->si_pid;
	if (client_pid != current_pid)
	{
		client_pid = current_pid;
		bit = 0;
		c = 0;
		received = 0;
	}
	c |= (sig == SIGUSR2);
	received++;
	bit++;
	if (bit == 8)
		print_char(&c, &received, &client_pid, &bit);
	c <<= 1;
	usleep(100);
	if (kill(client_pid, SIGUSR2) == -1)
		error_ms();
}

int	main(void)
{
	int					pid;
	struct sigaction	act;

	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	act.sa_sigaction = action;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	while (1)
	{
		sigaction(SIGUSR1, &act, 0);
		sigaction(SIGUSR2, &act, 0);
		pause();
	}
	return (0);
}
