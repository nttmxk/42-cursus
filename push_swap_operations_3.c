#include "push_swap.h"

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a, 0);
	rotate(b, 0);
	write(1, "rr\n", 3);
}

void	rrr(t_stack *a, t_stack *b)
{
	rotate(a, 1);
	rotate(b, 1);
	write(1, "rrr\n", 4);
}