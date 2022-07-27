/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinoh <jinoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:33:24 by jinoh             #+#    #+#             */
/*   Updated: 2022/07/22 15:33:25 by jinoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_info	*info;

	info = malloc(sizeof(t_info));
	if (!info)
		return (1);
	if (argc < 5 || argc > 6 || handle_input(argv, info))
		return (ft_error(info));
	return (philo_set(info));
}

int	philo_set(t_info *info)
{
	pthread_t		th[MAX_T];
	t_arg			arg[MAX_T];
	int				i;

	if (pthread_mutex_init(&info->mutex, NULL)
		|| pthread_mutex_lock(&info->mutex))
		return (ft_fail(info));
	i = -1;
	while (++i < info->nop)
	{
		arg[i].info = info;
		arg[i].i = (i + 1);
		arg[i].num_meal = 0;
		arg[i].last_meal = info->start;
		if (pthread_create(&th[i], NULL, philo_start, &arg[i]) != 0
			|| pthread_detach(th[i]))
			return (ft_fail(info));
	}
	if (pthread_mutex_unlock(&info->mutex))
		ft_fail(info);
	///////////////test
	size_t now;
	int k;
	while (!usleep(1000 * 50))
	{
		now = ft_getms();
		k = -1;
		printf("%zu ", now - info->start);
		while (++k < info->nop)
		{
			if (info->fork[k] == 1)
				printf("O ");
			else
				printf("X ");
//			printf("%d ", info->fork[k]);
			printf("%d ", k + 1);
		}
		printf("\n");
	}
	/////////////////test
//	philo_monitor(info);
	return (0);
}

void	philo_monitor(t_info *info)
{
	while (!info->kill && info->nop != info->not_p)
	{
		if (usleep(1))
		{
			info->kill = 1;
		}
	}
	pthread_mutex_unlock(&info->mutex);
	usleep(10000);
	free(info);
	info = NULL;
}
