#ifndef PHILO_H
# define PHILO_H

typedef struct s_info
{
	unsigned int NOP;
	unsigned int TTD;
	unsigned int TTE;
	unsigned int TTS;
	unsigned int NOT;
}	t_info;

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
