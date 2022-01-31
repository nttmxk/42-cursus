#include "ft_printf_bonus.h"

void	ft_printf_int(t_flag *pflag, int num, int *cnt)
{
	if (pflag->minus)
	{
		if (num < 0)
			(*cnt) += write(1, "-", 1);
		(*cnt) += ft_printf_int_str(pflag, num);
		ft_printf_int_space(pflag, num, cnt);
	}
	else
	{
		if (num < 0 && pflag->zero && !pflag->precision)
			(*cnt) += write(1, "-", 1);
		ft_printf_int_space(pflag, num, cnt);
		if (num < 0 && !(pflag->zero && !pflag->precision))
			(*cnt) += write(1, "-", 1);
		(*cnt) += ft_printf_int_str(pflag, num);
	}
}

int	ft_printf_int_str(t_flag *pflag, int num)
{
	int	len;
	int	cnt;
	int	precision;

	cnt = 0;
	len = ft_nbrlen(num);
	precision = pflag->precision;
	precision -= len;
	if (pflag->plus && num >= 0)
		cnt += write(1, "+", 1);
	while ((precision)-- > 0)
		cnt += write(1, "0", 1);
	if (pflag->dot && !pflag->precision && num == 0)
		len = 0;
	else
		ft_putnbr(num);
	return (cnt + len);
}

void	ft_printf_int_space(t_flag *pflag, int num, int *cnt)
{
	int		len;
	int		width;
	char	k;

	k = ' ';
	width = pflag->width;
	len = ft_nbrlen(num);
	if (num < 0 || (pflag->plus && num >= 0))
		width -= 1;
	if (pflag->space && num >= 0 && !pflag->plus)
	{
		(*cnt) += write(1, " ", 1);
		width -= 1;
	}
	if (pflag->precision > len)
		width -= pflag->precision;
	else
		width -= len;
	if (pflag->zero && !pflag->precision && num != 0)
		k = '0';
	if (pflag->dot && !pflag->precision && num == 0)
		++width;
	while (width-- > 0)
		(*cnt) += write(1, &k, 1);
}
