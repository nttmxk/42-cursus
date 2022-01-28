#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int		i;
	t_stack	a;
	t_stack	b;

	i = 0;
	if (argc < 2)
		return (0);
	while (++i < argc)
		check_input(argv[i]);
	createStack(&a, &b);
	ft_enqueue(&a, argv);
	check_dup(&a);
	sorting(&a, &b);
	return (0);
}
