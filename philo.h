/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinoh <jinoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:34:08 by jinoh             #+#    #+#             */
/*   Updated: 2022/07/22 15:34:09 by jinoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h> // gettime
# include <string.h> // memset
# define MAX_T 300

typedef struct s_info
{
	int				nop;
	int				ttd;
	int				tte;
	int				tts;
	int				not;
	int				not_p;
	int				kill;
	size_t			start;
	pthread_mutex_t	mutex;
	pthread_mutex_t	fork[MAX_T];
}	t_info;

typedef struct s_arg
{
	t_info	*info;
	size_t	last_meal;
	int		i;
	int		num_meal;
}	t_arg;

/*
 *	philo.c
 */
int					philo_set(t_info *info);
void				philo_monitor(t_info *info, t_arg *arg);
/*
 * 	philo_input.c
 */
int					handle_input(char *argv[], t_info *info);
/*
 * 	philo_lifecycle.c
 */
void				*philo_start(void *a);
/*
 * 	philo_lifecycle2.c
 */
void				put_chopsticks(t_arg *arg);
void				eating(t_arg *arg);
/*
 * 	philo_lifecycle_utils.c
 */
void				print_info(t_info *info, unsigned int i, int type);
void				check_starve(t_arg *arg);
int					ft_lock(t_info *info, int i);
int					ft_unlock(t_info *info, int i);
int					ft_usleep(useconds_t microseconds);
/*
 * 	philo_utils.c
 */
unsigned long long	ft_atol(const char *str);
size_t				ft_getms(void);
int					ft_error(t_info *info);
int					ft_fail(t_info *info);
void				*philo_err(t_info *info, int i);

#endif
