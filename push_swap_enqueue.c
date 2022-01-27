#include "push_swap.h"

static void	_enqueue(t_stack *a, int i);
static void	_enqueue_str(t_stack *a, const char *s);
static void	_rev_queue(t_stack *a);

void	ft_enqueue(t_stack *a, char *argv[])
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		if (ft_strchr(argv[i], ' '))
			_enqueue_str(a, argv[i]);
		else
			_enqueue(a, ft_atol(argv[i]));
	}
	_rev_queue(a);
}

static void	_enqueue(t_stack *a, int i)
{
	if (a->top + 1 >= ST_SIZE)
		ft_error();
	a->st[++a->top] = i;
}

static void	_enqueue_str(t_stack *a, const char *s)
{
	char	**str;
	int		i;

	str = ft_split(s, ' ');
	if (!str)
		ft_error();
	i = -1;
	while (str[++i])
		_enqueue(a, ft_atol(str[i]));
	free_str(str);
}

static void	_rev_queue(t_stack *a)
{
	int	i;
	int	tmp;

	i = -1;
	while (++i <= a->top / 2)
	{
		tmp = a->st[i];
		a->st[i] = a->st[a->top - i];
		a->st[a->top - i] = tmp;
	}
}