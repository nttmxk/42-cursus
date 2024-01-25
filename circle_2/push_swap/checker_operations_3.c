#include "checker.h"

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a, 0);
	rotate(b, 0);
}

void	rrr(t_stack *a, t_stack *b)
{
	rotate(a, 1);
	rotate(b, 1);
}
