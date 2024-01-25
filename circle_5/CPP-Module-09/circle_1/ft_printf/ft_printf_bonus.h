#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct s_flag
{
	int			minus;
	int			plus;
	int			zero;
	int			hash;
	int			space;
	int			width;
	int			dot;
	int			precision;
}	t_flag;

int		ft_printf(const char *fmt, ...);
void	ft_printf_2(const char *fmt, va_list *ap, int *cnt);
void	ft_set_flag(const char *fmt, t_flag *pflag);
void	ft_printf_parse(t_flag *pflag, va_list *ap, char c, int *cnt);
int		ft_is_conversion(char c);
t_flag	*create_flag(void);

void	ft_printf_char(t_flag *pflag, char c, int *cnt);
void	ft_printf_str(t_flag *pflag, char *str, int *cnt);

void	ft_printf_int(t_flag *pflag, int num, int *cnt);
int		ft_printf_int_str(t_flag *pflag, int num);
void	ft_printf_int_space(t_flag *pflag, int num, int *cnt);
int		ft_nbrlen(int num);
void	ft_putnbr(long long n);

void	ft_printf_uint(t_flag *pflag, unsigned int num, int *cnt);
int		ft_printf_uint_str(t_flag *pflag, unsigned int num);
int		ft_printf_uint_space(t_flag *pflag, unsigned int num);
int		ft_unbrlen(unsigned int num);
void	ft_putunbr(unsigned int n);

void	ft_printf_hexa(t_flag *pflag, unsigned long long n, int mode, int *cnt);
int		ft_printf_hexa_str(t_flag *pflag, char *num, int i, int mode);
int		ft_printf_hexa_space(t_flag *pflag, char num, int i, int mode);
void	ft_printf_percent(int *cnt);

#endif
