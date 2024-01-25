#include "push_swap.h"

static void	_sorting(t_stack *a, t_stack *b);
static void	_sort_3(t_stack *a);
static void	_sort_5(t_stack *a, t_stack *b);
static void	ft_get_optimal(int *i, int *j, int a, int b);

void	sorting(t_stack *a, t_stack *b)
{
	int	size;
	int	lis[ST_SIZE + 1];

	if (a->top == 2)
		_sort_3(a);
	else if (a->top == 4)
		_sort_5(a, b);
	else
	{
		get_lis(a, lis, 0);
		size = a->top;
		separate_stack(a, b, lis);
		while (size != a->top)
			_sorting(a, b);
	}
	get_mintop(a);
}

static void	_sorting(t_stack *a, t_stack *b)
{
	int	i;
	int	min_moves;
	int	moves[ST_SIZE][3];

	i = -1;
	min_moves = 0;
	while (++i <= b->top)
	{
		moves[i][0] = ft_min(b->top - i, i + 1);
		moves[i][1] = ft_get_move(a, b->st[i]);
		if (moves[i][0] * moves[i][1] < 0)
			ft_get_optimal(&moves[i][0], &moves[i][1], a->top, b->top);
		moves[i][2] = ft_get_min_move(moves[i][0], moves[i][1]);
		if (moves[i][2] < moves[min_moves][2])
			min_moves = i;
	}
	if (moves[min_moves][0] > 0 && moves[min_moves][1] > 0)
		ft_both_r(a, b, moves[min_moves][1], moves[min_moves][0]);
	else if (moves[min_moves][0] < 0 && moves[min_moves][1] < 0)
		ft_both_rr(a, b, moves[min_moves][1], moves[min_moves][0]);
	else
		ft_sep_move(a, b, moves[min_moves][1], moves[min_moves][0]);
	pa(a, b);
}

static void	_sort_3(t_stack *a)
{
	int	i;
	int	j;
	int	k;

	i = a->st[2];
	j = a->st[1];
	k = a->st[0];
	if ((i > j && i > k && j < k)
		|| (i < j && j > k && i > k)
		|| (i < j && i < k && j < k))
		return ;
	else if (i > j && i > k)
	{
		ra(a);
		sa(a);
	}
	else if (i > j && i < k)
	{
		sa(a);
	}
	else
	{
		rra(a);
		sa(a);
	}
}

static void	_sort_5(t_stack *a, t_stack *b)
{
	pb(a, b);
	pb(a, b);
	_sort_3(a);
	while (b->top != -1)
		_sorting(a, b);
}

static void	ft_get_optimal(int *i, int *j, int a, int b)
{
	if ((*i) < 0)
	{
		if (ft_get_min_move((*j), b + (*i) + 1)
			< ft_get_min_move((*i), - (a - (*j) + 1)))
		{
			if ((*j) - (*i) > ft_get_min_move((*j), b + (*i) + 1))
				(*i) = b + (*i) + 1;
		}
		else if ((*j) - (*i) > ft_get_min_move((*i), -(a - (*j) + 1)))
			(*j) = -(a - (*j) + 1);
	}
	else
	{
		if (ft_get_min_move((*j), -(b - (*i) + 1))
			< ft_get_min_move((*i), a + (*j) + 1))
		{
			if ((*i) - (*j) > ft_get_min_move((*j), -(b - (*i) + 1)))
				(*i) = -(b - (*i) + 1);
		}
		else if ((*i) - (*j) > ft_get_min_move((*i), a + (*j) + 1))
			(*j) = a + (*j) + 1;
	}
}
