#include "ft_printf_bonus.h"

void	ft_printf_uint(t_flag *pflag, unsigned int num, int *cnt)
{
	if (pflag->minus)
	{
		(*cnt) += ft_printf_uint_str(pflag, num);
		(*cnt) += ft_printf_uint_space(pflag, num);
	}
	else
	{
		(*cnt) += ft_printf_uint_space(pflag, num);
		(*cnt) += ft_printf_uint_str(pflag, num);
	}
}

int	ft_printf_uint_str(t_flag *pflag, unsigned int num)
{
	int	len;
	int	cnt;
	int	precision;

	cnt = 0;
	len = ft_unbrlen(num);
	precision = pflag->precision;
	precision -= len;
	if (pflag->plus)
		cnt += write(1, "+", 1);
	while ((precision)-- > 0)
		cnt += write(1, "0", 1);
	if (num == 0 && pflag->dot && !pflag->precision)
		len = 0;
	else
		ft_putunbr(num);
	return (cnt + len);
}

int	ft_printf_uint_space(t_flag *pflag, unsigned int num)
{
	int		len;
	int		cnt;
	int		width;
	char	k;

	cnt = 0;
	k = ' ';
	width = pflag->width;
	len = ft_unbrlen(num);
	if (pflag->plus)
		width -= 1;
	if (pflag->space && !pflag->plus)
	{
		cnt += write(1, " ", 1);
		width -= 1;
	}
	if (pflag->precision > len)
		width -= pflag->precision;
	else if (num != 0 || !pflag->dot || pflag->precision)
		width -= len;
	if (pflag->zero && !pflag->precision && num != 0)
		k = '0';
	while (width-- > 0)
		cnt += write(1, &k, 1);
	return (cnt);
}
