#include "checker.h"

void	ft_parse(char *s, t_stack *a, t_stack *b)
{
	if (s[0] == 's')
		ft_parse_s(s, a, b);
	else if (s[0] == 'p')
		ft_parse_p(s, a, b);
	else if (s[0] == 'r')
		ft_parse_r(s, a, b);
	else
		ft_error();
}

void	ft_parse_s(char *s, t_stack *a, t_stack *b)
{
	if (s[1] == 'a' && s[2] == '\n' && s[3] == '\0')
		sa(a);
	else if (s[1] == 'b' && s[2] == '\n' && s[3] == '\0')
		sb(b);
	else if (s[1] == 's' && s[2] == '\n' && s[3] == '\0')
		ss(a, b);
	else
		ft_error();
}

void	ft_parse_p(char *s, t_stack *a, t_stack *b)
{
	if (s[1] == 'a' && s[2] == '\n' && s[3] == '\0')
		pa(a, b);
	else if (s[1] == 'b' && s[2] == '\n' && s[3] == '\0')
		pb(a, b);
	else
		ft_error();
}

void	ft_parse_r(char *s, t_stack *a, t_stack *b)
{
	if (s[1] == 'a' && s[2] == '\n' && s[3] == '\0')
		ra(a);
	else if (s[1] == 'b' && s[2] == '\n' && s[3] == '\0')
		rb(b);
	else if (s[1] == 'r')
	{
		if (s[2] == '\n' && s[3] == '\0')
			rr(a, b);
		else if (s[2] == 'a' && s[3] == '\n' && s[4] == '\0')
			rra(a);
		else if (s[2] == 'b' && s[3] == '\n' && s[4] == '\0')
			rrb(b);
		else if (s[2] == 'r' && s[3] == '\n' && s[4] == '\0')
			rrr(a, b);
		else
			ft_error();
	}
	else
		ft_error();
}
