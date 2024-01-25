#include "checker.h"

static void	_get_lis(t_stack *a, int *ret, int size, int *lis);

void	get_lis(t_stack *a, int *lis, int i)
{
	int	size;
	int	pos;
	int	dp[ST_SIZE];
	int	ret[ST_SIZE];

	size = 0;
	dp[0] = a->st[0];
	ret[0] = 0;
	while (++i <= a->top)
	{
		if (dp[size] > a->st[i])
		{
			dp[++size] = a->st[i];
			pos = size;
		}
		else
		{
			pos = b_search(dp, a->st[i], 0, size);
			if (pos != -1 && pos <= size)
				dp[pos] = a->st[i];
		}
		ret[i] = pos;
	}
	_get_lis(a, ret, size, lis);
}

static void	_get_lis(t_stack *a, int *ret, int size, int *lis)
{
	int	i;

	i = a->top + 1;
	lis[0] = size + 1;
	while (size >= 0)
	{
		while (ret[--i] != size)
			;
		lis[size + 1] = a->st[i];
		--size;
	}
}

int	b_search(int *dp, int a, int s, int e)
{
	int	mid;

	mid = (s + e) / 2;
	if (s == e)
	{
		if (dp[s] < a)
			return (s);
		else
			return (-1);
	}
	if (dp[mid] > a)
		return (b_search(dp, a, mid + 1, e));
	else
		return (b_search(dp, a, s, mid));
}
