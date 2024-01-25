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

static int	philo_before_start(t_arg *arg);
static void	take_chopsticks(t_arg *arg);
static void	take_fore(t_arg *arg);
static void	take_foro(t_arg *arg);
/*
 * 	idea:
 * 			[] some func should be a static func
 */

void	*philo_start(void *a)
{
	t_arg	*arg;

	arg = (t_arg *) a;
	if (philo_before_start(arg))
		return (0);
	while (!arg->info->kill && arg->num_meal != arg->info->not)
	{
		take_chopsticks(arg);
		eating(arg);
		if (arg->info->kill || arg->last_meal == 0
			|| ft_usleep(arg->info->tte * 1000))
			return (philo_err(arg->info, -1));
		put_chopsticks(arg);
		if (arg->num_meal == arg->info->not)
			break ;
		if (arg->info->kill || ft_usleep(arg->info->tts * 1000))
			return (philo_err(arg->info, -1));
		print_info(arg->info, arg->i, 3);
		if (ft_usleep(150))
			return (philo_err(arg->info, -1));
	}
	if (arg->num_meal == arg->info->not)
		arg->info->not_p++;
	return (0);
}

static int	philo_before_start(t_arg *arg)
{
	if (pthread_mutex_lock(&arg->info->mutex)
		|| pthread_mutex_unlock(&arg->info->mutex))
	{
		philo_err(arg->info, -1);
		return (1);
	}
	if (arg->info == NULL || arg->info->kill)
	{
		return (1);
	}
	if (arg->i % 2 == 0 && ft_usleep(3 * 1000))
	{
		philo_err(arg->info, -1);
		return (1);
	}
	return (0);
}

static void	take_chopsticks(t_arg *arg)
{
	if (arg->i % 2)
		take_foro(arg);
	else
		take_fore(arg);
	print_info(arg->info, arg->i, 0);
}

static void	take_fore(t_arg *arg)
{
	unsigned int	i;

	i = arg->i - 1;
	if (ft_lock(arg->info, i)
		|| ft_lock(arg->info, (i + 1) % arg->info->nop))
		return ;
}

static void	take_foro(t_arg *arg)
{
	unsigned int	i;

	i = arg->i - 1;
	if (ft_lock(arg->info, (i + 1) % arg->info->nop)
		|| ft_lock(arg->info, i))
		return ;
}
