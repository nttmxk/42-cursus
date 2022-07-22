/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_lifecycle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinoh <jinoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:33:37 by jinoh             #+#    #+#             */
/*   Updated: 2022/07/22 15:33:39 by jinoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
 * 	idea:
 * 			[] pthread error handling
 * 			[] mutex_lock guard
 * 			[] action and print info merge, no need to be seperated.
 */

void	*philo_start(void *a)
{
	t_arg	*arg;

	arg = (t_arg *)a;
	pthread_mutex_lock(&arg->info->mutex); // lock guard
	pthread_mutex_unlock(&arg->info->mutex);
	if (arg->info == NULL || arg->info->kill)
		return (0);
	if (arg->i % 2 == 0 && usleep(100))
		return (philo_err(arg->info));
	while (!arg->info->kill && arg->num_meal != arg->info->NOT)
	{
		take_chopsticks(arg);
		print_info(arg->info, arg->i, 0);
		print_info(arg->info, arg->i, 1);
		arg->num_meal++;
		arg->last_meal = ft_getms();
		if (arg->last_meal == 0 || usleep(arg->info->TTE * 1000))
			return (philo_err(arg->info));
		put_chopsticks(arg);
		print_info(arg->info, arg->i, 2);
		if (usleep(arg->info->TTS * 1000))
			return (philo_err(arg->info));
		check_starve(arg);
		print_info(arg->info, arg->i, 3);
		usleep(500);
	}
	return (0);
}

void	take_chopsticks(t_arg *arg)
{
	unsigned int	i;
	int				cond;

	cond = 1;
	i = arg->i - 1;
	while (cond && !arg->info->kill)
	{
		pthread_mutex_lock(&arg->info->mutex); // lock guard
		if (arg->info->fork[i] && arg->info->fork[((i + 1) % arg->info->NOP)])
		{
			arg->info->fork[i] = 0;
			arg->info->fork[((i + 1) % arg->info->NOP)] = 0;
			cond = 0;
		}
		pthread_mutex_unlock(&arg->info->mutex);
		if (cond)
		{
			if (usleep(50))
				philo_err(arg->info);
		}
		if (arg->info->kill)
			return ;
		else
			check_starve(arg);
	}
}

void	put_chopsticks(t_arg *arg)
{
	unsigned int	i;

	i = arg->i - 1;
	pthread_mutex_lock(&arg->info->mutex); // lock defense
	arg->info->fork[i] = 1;
	arg->info->fork[((i + 1) % arg->info->NOP)] = 1;
	pthread_mutex_unlock(&arg->info->mutex);
}
