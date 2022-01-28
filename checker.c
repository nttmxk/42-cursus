#include "checker.h"

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
	getinput(&a, &b);
	return (0);
}

void	getinput(t_stack *a, t_stack *b)
{
	int		lis[ST_SIZE + 1];
	char	*line;

	while (1)
	{
		line = NULL;
		write(1, "Enter\n", 6);
		while (!line)
			line = get_next_line(0);
		if (line && line[0] == -1)
			break;
		ft_parse(line, a, b);
		free(line);
	}
	free(line);
	get_lis(a, lis, 0);
	if (lis[0] != a->top)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
}
