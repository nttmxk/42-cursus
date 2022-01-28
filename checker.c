#include "checker.h"

int	main(int argc, char *argv[])
{
	int		i;
	t_stack	a;
	t_stack	b;

	i = 0;
	if (argc < 2) // check it
		return (0);
	while (++i < argc)
		check_input(argv[i]);
	createStack(&a, &b);
	ft_enqueue(&a, argv);
	check_dup(&a);
	getinput(&a, &b);
	return (0);
}

void	getinput(t_stack *a, t_stack *b)
{
	int		size;
	int		r_size;
	int		lis[ST_SIZE + 1];
	char	*line;

	line = get_next_line(0);
	while (!line)
	{
		ft_parse(line, a, b);
		free(line);
		line = get_next_line(0);
	}
	get_lis(a, lis, 0);
	if (lis[0] != a->top)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
}