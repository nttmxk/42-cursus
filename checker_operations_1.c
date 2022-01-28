#include "checker.h"

void	sa(t_stack *a)
{
	swap(a);
}

void	sb(t_stack *b)
{
	swap(b);
}

void	pa(t_stack *a, t_stack *b)
{
	push(b, a);
}

void	pb(t_stack *a, t_stack *b)
{
	push(a, b);
}
