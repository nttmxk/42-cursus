/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_lifecycle_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinoh <jinoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:33:57 by jinoh             #+#    #+#             */
/*   Updated: 2022/07/22 15:33:58 by jinoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_info(t_info *info, unsigned int i, int type)
{
	size_t	now;

	if (ft_lock(info, -1) || info->kill)
		return ;
	now = ft_getms();
	if (now == 0)
	{
		philo_err(info, -1);
		return ;
	}
	if (type == 0)
		printf("%zu %d has taken a fork\n", now - info->start, i);
	else if (type == 1)
		printf("%zu %d is eating\n", now - info->start, i);
	else if (type == 2)
		printf("%zu %d is sleeping\n", now - info->start, i);
	else if (type == 3)
		printf("%zu %d is thinking\n", now - info->start, i);
	else
	{
		printf("%zu %d died\n", now - info->start, i);
		info->kill = 1;
	}
	ft_unlock(info, -1);
}

void	check_starve(t_arg *arg)
{
	size_t	now;

	now = ft_getms();
	if (now == 0)
	{
		philo_err(arg->info, -1);
		return ;
	}
	if ((int)(now - arg->last_meal) >= arg->info->ttd)
	{
		print_info(arg->info, arg->i, 4);
		ft_unlock(arg->info, arg->i);
		ft_unlock(arg->info, (arg->i + 1) % arg->info->nop);
	}
}

int	ft_usleep(useconds_t microseconds)
{
	size_t	target;
	size_t	now;

	target = ft_getms() + microseconds / 1000;
	if (target == 0)
		return (1);
	while (1)
	{
		now = ft_getms();
		if (now == 0)
			return (1);
		if (target < now)
			break ;
		if (usleep(180))
			return (1);
	}
	return (0);
}

int	ft_lock(t_info *info, int i)
{
	if (i == -1)
	{
		if (pthread_mutex_lock(&info->mutex))
		{
			philo_err(info, i);
			return (1);
		}
	}
	else if (pthread_mutex_lock(&info->fork[i]))
	{
		philo_err(info, i);
		return (1);
	}
	return (0);
}

int	ft_unlock(t_info *info, int i)
{
	if (i == -1)
	{
		if (pthread_mutex_unlock(&info->mutex))
		{
			philo_err(info, i);
			return (1);
		}
	}
	else if (pthread_mutex_unlock(&info->fork[i]))
	{
		philo_err(info, i);
		return (1);
	}
	return (0);
}
