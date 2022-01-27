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
			rra(b);
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
		while (i-- < 0)
			rr(a, b);
	}
}
