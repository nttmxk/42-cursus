#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h> // gettime
# include <string.h> // memset
# define MAX_T 500
typedef struct s_info
{
	unsigned int NOP;
	unsigned int TTD;
	unsigned int TTE;
	unsigned int TTS;
	unsigned int NOT;
	unsigned int kill;
	size_t start;
	pthread_mutex_t mutex;
	char fork[MAX_T];
}	t_info;

typedef struct s_arg
{
	t_info			*info;
	size_t			last_meal;
	unsigned int	i;
}	t_arg;

/*
 * 	philo.c
 */
int		philo_start(t_info *info);
int		ft_error(void);
int		handle_input(char *argv[], t_info *info);
void	*philo(void *a);
void	take_chopsticks(t_arg *arg);
void	put_chopsticks(t_arg *arg);
void	print_info(t_info *info, unsigned int i, int type);
void	check_starve(t_arg *arg);

/*
 * 	philo_input.c
 */
int handle_input(char *argv[], t_info *info);
int ft_error(void);

/*
 * 	philo_utils.c
 */
unsigned long long	ft_atol(const char *str);
size_t				ft_gettime(struct timeval s);
size_t				ft_getms(void);
void				print_info(t_info *info, unsigned int i, int type);

#endif
