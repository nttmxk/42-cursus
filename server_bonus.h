#ifndef SERVER_BONUS_H
# define SERVER_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

int	ft_printf(const char *fmt, ...);
int	check_pid(siginfo_t *info, int *pid);
void	ft_error(void);
void	sig_handler(int signo, siginfo_t *info, void *context);
void	set_sig(struct sigaction *act);

#endif
