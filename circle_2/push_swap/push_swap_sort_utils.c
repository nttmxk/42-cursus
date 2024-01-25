#include "push_swap.h"

int	ft_get_min_move(int a, int b)
{
	if (a > 0 && b > 0)
	{
		if (a > b)
			return (a);
		else
			return (b);
	}
	else if (a < 0 && b < 0)
	{
		if (a > b)
			return (-b);
		else
			return (-a);
	}
	else
	{
		if (a < 0)
			return (b - a);
		else if (b < 0)
			return (a - b);
	}
	return (a + b);
}

int	ft_get_move(t_stack *a, int b)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (++i <= a->top)
		if (a->st[i] > a->st[i - 1])
			j = i;
	i = 0;
	if (j == 0 && (b < a->st[a->top] || b > a->st[0]))
		return (0);
	if (j != 0 && (b < a->st[j - 1] || b > a->st[j]))
		return (ft_min(a->top - j + 1, j));
	while (++i <= a->top)
	{
		if (b < a->st[i - 1] && b > a->st[i])
			return (ft_min(a->top - i + 1, i));
	}
	if (b < a->st[a->top] && b > a->st[0])
		return (0);
	write(2, "Error2\n", 7);
	return (5000);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (-b);
}
