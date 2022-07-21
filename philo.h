#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h> // gettime
# include <string.h> // memset
# define MAX_T 300

typedef struct	s_info
{
	int				NOP;
	int				TTD;
	int				TTE;
	int				TTS;
	int				NOT;
	int				kill;
	size_t			start;
	pthread_mutex_t	mutex;
	char			fork[MAX_T];
}	t_info;

typedef struct	s_arg
{
	t_info	*info;
	size_t	last_meal;
	int		i;
	int		num_meal;
}	t_arg;

/*
 *	philo.c
 */
int		philo_set(t_info *info);
void	philo_monitor(t_info *info);

/*
 * 	philo_input.c
 */
int	handle_input(char *argv[], t_info *info);

/*
 * 	philo_lifecycle.c
 */
void	*philo_start(void *a);
void	take_chopsticks(t_arg *arg);
void	put_chopsticks(t_arg *arg);

/*
 * 	philo_lifecycle_utils.c
 */
void	check_starve(t_arg *arg);


/*
 * 	philo_utils.c
 */
unsigned long long	ft_atol(const char *str);
void				print_info(t_info *info, unsigned int i, int type);
size_t				ft_getms(void);
int					ft_error(t_info *info);
int					ft_exit(t_info *info);

#endif