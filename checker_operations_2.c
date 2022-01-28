#include "checker.h"

void	ra(t_stack *a)
{
	rotate(a, 0);
}

void	rb(t_stack *b)
{
	rotate(b, 0);
}

void	rra(t_stack *a)
{
	rotate(a, 1);
}

void	rrb(t_stack *b)
{
	rotate(b, 1);
}
