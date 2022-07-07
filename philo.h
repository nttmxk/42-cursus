#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h> // gettime
# include <string.h> // memset

typedef struct s_info
{
	unsigned int NOP;
	unsigned int TTD;
	unsigned int TTE;
	unsigned int TTS;
	unsigned int NOT;
	unsigned int kill;
	char fork[500];
	struct timeval start;
	pthread_mutex_t mutex;
}	t_info;

typedef struct s_arg
{
	t_info			*info;
	struct timeval	last_meal;
	unsigned int	i;
}	t_arg;

/*
 * 	philo.c
 */
int	philo_start(t_info *info);
int ft_error(void);
int handle_input(char *argv[], t_info *info);

/*
 * 	philo_utils.c
 */
unsigned long long	ft_atol(const char *str);


#endif
