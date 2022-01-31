#include "push_swap.h"
static void	check_digit_s(char *s);
static void	check_digit_str(char *s);

void	check_input(char *s)
{
	if (ft_strchr(s, ' '))
		check_digit_str(s);
	else
		check_digit_s(s);
}

static void	check_digit_s(char *s)
{
	int	i;

	i = -1;
	if (!s[0])
		ft_error();
	if (s[0] == '+' || s[0] == '-')
		++i;
	while (s[++i])
	{
		if (!ft_isdigit(s[i]))
			ft_error();
	}
}

static void	check_digit_str(char *s)
{
	int		i;
	char	**str;

	str = ft_split(s, ' ');
	if (!str)
		ft_error();
	i = -1;
	while (str[++i])
		check_digit_s(str[i]);
	free_str(str);
}

void	check_dup(t_stack *a)
{
	int	i;
	int	j;

	i = -1;
	while (++i < a->top)
	{
		j = i;
		while (++j <= a->top)
		{
			if (a->st[i] == a->st[j])
				ft_error();
		}
	}
}
