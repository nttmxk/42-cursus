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

	if (ft_lock(info) || info->kill)
		return ;
	now = ft_getms();
	if (now == 0)
	{
		philo_err(info);
		return ;
	}
	if (type == 0)
		printf("%zums %d has taken a fork\n", now - info->start, i);
	else if (type == 1)
		printf("%zums %d is eating\n", now - info->start, i);
	else if (type == 2)
		printf("%zums %d is sleeping\n", now - info->start, i);
	else if (type == 3)
		printf("%zums %d is thinking\n", now - info->start, i);
	else
	{
		printf("%zums %d died\n", now - info->start, i);
		info->kill = 1;
	}
    ft_unlock(info);
}

void	check_starve(t_arg *arg)
{
	size_t	now;

	now = ft_getms();
	if (now == 0)
	{
		philo_err(arg->info);
		return ;
	}
	if ((int)(now - arg->last_meal) >= arg->info->ttd)
		print_info(arg->info, arg->i, 4);
}

int ft_lock(t_info *info)
{
    if (pthread_mutex_lock(&info->mutex))
    {
        philo_err(arg->info);
        return (1);
    }
    return (0);
}

int ft_unlock(t_info *info)
{
    if (pthread_mutex_unlock(&info->mutex))
    {
        philo_err(arg->info);
        return (1);
    }
    return (0);
}