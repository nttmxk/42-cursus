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

static int philo_before_start(t_arg *arg);
static void take_chopsticks(t_arg *arg);
static void take_fore(t_arg *arg);
static void take_foro(t_arg *arg);

/*
 * 	idea:
 * 			[] pthread error handling
 * 			[] mutex_lock guard
 * 			[] action and print info merge, no need to be seperated.
 * 			[] When nop is 1, philosopher should be die!
 * 			[] some func should be a static func
 * 			[] Philosophers visualizer?
 */

void	*philo_start(void *a)
{
	t_arg	*arg;

	arg = (t_arg *)a;
	if (philo_before_start(arg))
	    return (0);
	while (!arg->info->kill && arg->num_meal != arg->info->not)
	{
		take_chopsticks(arg);
		eating(arg);
		if (arg->info->kill || arg->last_meal == 0 || usleep(arg->info->tte * 1000))
			return (philo_err(arg->info));
		put_chopsticks(arg);
		if (arg->info->kill || usleep(arg->info->tts * 1000))
			return (philo_err(arg->info));
		check_starve(arg);
		print_info(arg->info, arg->i, 3);
	}
	if (arg->num_meal == arg->info->not)
		arg->info->not_p++;
	return (0);
}

static int philo_before_start(t_arg *arg)
{
    if (pthread_mutex_lock(&arg->info->mutex) || pthread_mutex_unlock(&arg->info->mutex))
    {
        philo_err(arg->info);
        return (1);
    }
    if (arg->info == NULL || arg->info->kill)
        return (1);
    if (arg->i % 2 == 0 && usleep(100))
    {
        philo_err(arg->info);
        return (1);
    }
    return (0);
}

static void take_chopsticks(t_arg *arg)
{
    if (arg->i % 2)
        take_foro(arg);
    else
        take_fore(arg);
    print_info(arg->info, arg->i, 0);
}

static void take_fore(t_arg *arg)
{
    unsigned int	i;
    int				cond;

    cond = 1;
    i = arg->i - 1;
    while (cond && !arg->info->kill)
    {
        if (ft_lock(arg->info))
            return ;
        if (arg->info->fork[i])
        {
            arg->info->fork[i] = 0;
            cond = 2;
        }
        if (cond == 2 && arg->info->fork[(i + 1) % arg->info->nop])
        {
            arg->info->fork[((i + 1) % arg->info->nop)] = 0;
            cond = 0;
        }
        if (ft_unlock(arg->info))
            return ;
        check_starve(arg);
    }
}

static void take_foro(t_arg *arg)
{
    unsigned int	i;
    int				cond;

    cond = 1;
    i = arg->i - 1;
    while (cond && !arg->info->kill)
    {
        if (ft_lock(arg->info))
            return ;
        if (arg->info->fork[(i + 1) % arg->info->nop])
        {
            arg->info->fork[((i + 1) % arg->info->nop)] = 0;
            cond = 2;
        }
        if (cond == 2 && arg->info->fork[i])
        {
            arg->info->fork[i] = 0;
            cond = 0;
        }
        if (ft_unlock(arg->info))
            return ;
//        if (cond)
//        {
//            if (usleep(50))
//                philo_err(arg->info);
//        }
        check_starve(arg);
    }
}