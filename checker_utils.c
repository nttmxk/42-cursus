#include "checker.h"

void	free_str(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		free(str[i]);
		str[i] = NULL;
	}
	free(str);
	str = NULL;
}

void	createStack(t_stack *a, t_stack *b)
{
	a->top = -1;
	b->top = -1;
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
