/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_lifecycle2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinoh <jinoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:33:37 by jinoh             #+#    #+#             */
/*   Updated: 2022/07/22 15:33:39 by jinoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	put_fore(t_arg *arg);
static void	put_foro(t_arg *arg);

void	eating(t_arg *arg)
{
	print_info(arg->info, arg->i, 1);
	arg->num_meal++;
	arg->last_meal = ft_getms();
}

void	put_chopsticks(t_arg *arg)
{
	if (arg->i % 2)
		put_foro(arg);
	else
		put_fore(arg);
	print_info(arg->info, arg->i, 2);
}

static void	put_fore(t_arg *arg)
{
	unsigned int	i;

	i = arg->i - 1;
	if (ft_lock(arg->info))
		return ;
	arg->info->fork[i] = 1;
	if (ft_unlock(arg->info))
		return ;
	if (ft_lock(arg->info))
		return ;
	arg->info->fork[((i + 1) % arg->info->nop)] = 1;
	if (ft_unlock(arg->info))
		return ;
}

static void	put_foro(t_arg *arg)
{
	unsigned int	i;

	i = arg->i - 1;
	if (ft_lock(arg->info))
		return ;
	arg->info->fork[((i + 1) % arg->info->nop)] = 1;
	if (ft_unlock(arg->info))
		return ;
	if (ft_lock(arg->info))
		return ;
	arg->info->fork[i] = 1;
	if (ft_unlock(arg->info))
		return ;
}
