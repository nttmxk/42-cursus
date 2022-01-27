#include "push_swap.h"

void	ra(t_stack *a)
{
	rotate(a, 0);
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	rotate(b, 0);
	write(1, "rb\n", 3);
}

void	rra(t_stack *a)
{
	rotate(a, 1);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	rotate(b, 1);
	write(1, "rrb\n", 4);
}
