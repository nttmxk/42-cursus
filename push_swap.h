#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h> // write read
# include <stdlib.h> // malloc free exit
# include <limits.h> // INT_MAX
# define ST_SIZE 1000

typedef struct s_stack
{
	int	top;
	int	st[ST_SIZE];
}	t_stack;
/*
 * input check
 */
void	check_input(char *s);
void	ft_enqueue(t_stack *a, char *argv[]);
void	free_str(char **str);
void	check_dup(t_stack *a);
/*
 * utils
 */
void	createStack(t_stack *a, t_stack *b);
void	ft_error(void);
void	get_lis(t_stack *a, int *lis, int i);
int		ft_atol(const char *s);
int		b_search(int *dp, int a, int s, int e);
int		ft_get_min_move(int a, int b);
int		ft_get_move(t_stack *a, int b);
int		ft_min(int a, int b);
/*
 * sorting
 */
void	sorting(t_stack *a, t_stack *b);
void	get_mintop(t_stack *a);
void	separate_stack(t_stack *a, t_stack *b, int *lis);
void	ft_sep_move(t_stack *a, t_stack *b, int i, int j);
void	ft_both_rr(t_stack *a, t_stack *b, int i, int j);
void	ft_both_r(t_stack *a, t_stack *b, int i, int j);
/*
 * basic operations
 */
void	swap(t_stack *s);
void	push(t_stack *from, t_stack *to);
void	rotate(t_stack *s, int reverse);
/*
 * operations
 */
void	sa(t_stack *a);
void	sb(t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rrr(t_stack *a, t_stack *b);

#endif
