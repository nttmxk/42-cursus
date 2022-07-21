#include "philo.h"

void check_starve(t_arg *arg)
{
	size_t	now;

	now = ft_getms();
	if (now == 0)
		ft_exit(arg->info);
	if (now - arg->last_meal >= arg->info->TTD) // starving check
	{
		arg->info->kill = 1;
		print_info(arg->info, arg->i, 4);
	}
}