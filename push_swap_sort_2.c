#include "push_swap.h"

void	ft_sep_move(t_stack *a, t_stack *b, int i, int j)
{
	if (i > 0)
	{
		while (i-- > 0)
			ra(a);
	}
	else
	{
		while (i++ < 0)
			rra(a);
	}
	if (j > 0)
	{
		while (j-- > 0)
			rb(b);
	}
	else
	{
		while (j++ < 0)
			rrb(b);
	}
}

void	ft_both_rr(t_stack *a, t_stack *b, int i, int j)
{
	if (i > j)
	{
		while (i > j++)
			rrb(b);
		while (i++ < 0)
			rrr(a, b);
	}
	else
	{
		while (i++ < j)
			rra(a);
		while (j++ < 0)
			rrr(a, b);
	}
}

void	ft_both_r(t_stack *a, t_stack *b, int i, int j)
{
	if (i > j)
	{
		while (i-- > j)
			ra(a);
		while (j-- > 0)
			rr(a, b);
	}
	else
	{
		while (i < j--)
			rb(b);
		while (i-- > 0)
			rr(a, b);
	}
}

void	get_mintop(t_stack *a)
{
	int	i;
	int	min;
	int	minx;

	i = -1;
	min = 2147483647;
	while (++i <= a->top)
	{
		if (a->st[i] < min)
		{
			min = a->st[i];
			minx = i;
		}
	}
	if (minx >= a->top / 2)
	{
		while (++minx <= a->top)
			ra(a);
	}
	else
		while (--minx >= -1)
			rra(a);
}

void	separate_stack(t_stack *a, t_stack *b, int *lis)
{
	int	size;
	int	total;
	int	push;

	size = lis[0];
	push = 0;
	total = a->top + 1 - size;
	while (push != total)
	{
		if (size > 0 && a->st[a->top] == lis[size])
		{
			ra(a);
			--size;
		}
		else
		{
			pb(a, b);
			++push;
		}
	}
}
