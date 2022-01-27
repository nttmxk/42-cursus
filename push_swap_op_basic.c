#include "push_swap.h"

void	swap(t_stack *s)
{
	int	tmp;

	if (s->top > 0)
	{
		tmp = s->st[s->top];
		s->st[s->top] = s->st[s->top - 1];
		s->st[s->top - 1] = tmp;
	}
}

void	push(t_stack *from, t_stack *to)
{
	if (to->top + 1 >= ST_SIZE)
		ft_error();
	if (from->top > -1)
		to->st[++(to->top)] = from->st[(from->top)--];
}

void	rotate(t_stack *s, int reverse)
{
	int	tmp;
	int	i;

	if (s->top < 1)
		return ;
	if (reverse)
	{
		i = 0;
		tmp = s->st[0];
		while (++i <= s->top)
			s->st[i - 1] = s->st[i];
		s->st[s->top] = tmp;
	}
	else
	{
		i = s->top;
		tmp = s->st[s->top];
		while (--i >= 0)
			s->st[i + 1] = s->st[i];
		s->st[0] = tmp;
	}
}