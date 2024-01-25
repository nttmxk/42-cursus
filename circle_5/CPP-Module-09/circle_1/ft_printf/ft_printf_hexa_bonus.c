#include "ft_printf_bonus.h"

void	ft_printf_hexa(t_flag *pflag, unsigned long long n, int mode, int *cnt)
{
	int				i;
	char			num[32];
	char			*base;

	if (mode == 1)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	i = -1;
	while (n >= 16)
	{
		num[++i] = base[n % 16];
		n /= 16;
	}
	num[++i] = base[n % 16];
	if (pflag->minus)
	{
		(*cnt) += ft_printf_hexa_str(pflag, num, i, mode);
		(*cnt) += ft_printf_hexa_space(pflag, num[i], i, mode);
	}
	else
	{
		(*cnt) += ft_printf_hexa_space(pflag, num[i], i, mode);
		(*cnt) += ft_printf_hexa_str(pflag, num, i, mode);
	}
}

int	ft_printf_hexa_str(t_flag *pflag, char *num, int i, int mode)
{
	int	cnt;
	int	precision;

	cnt = i + 1;
	precision = pflag->precision;
	precision -= i + 1;
	if (mode == 2 || (mode == 1 && pflag->hash) || (mode == 0 && pflag->hash))
		precision -= 2;
	if (mode == 2)
		cnt += write(1, "0x", 2);
	else if ((mode == 0 && pflag->hash) && !(i == 0 && num[i] == '0'))
		cnt += write(1, "0x", 2);
	else if (mode == 1 && pflag->hash && !(i == 0 && num[i] == '0'))
		cnt += write(1, "0X", 2);
	while ((precision)-- > 0)
		cnt += write(1, "0", 1);
	if (!(i == 0 && num[i] == '0' && pflag->dot && !pflag->precision))
	{
		while (i >= 0)
			write(1, &num[i--], 1);
	}
	else
		cnt -= i + 1;
	return (cnt);
}

int	ft_printf_hexa_space(t_flag *pflag, char num, int i, int mode)
{
	int		cnt;
	int		width;
	char	k;

	cnt = 0;
	k = ' ';
	width = pflag->width;
	if (mode == 2 || (mode == 1 && pflag->hash) || (mode == 0 && pflag->hash))
		width -= 2;
	if (pflag->precision > i + 1)
		width -= pflag->precision;
	else if (!(pflag->dot && !pflag->precision && i == 0 && num == '0'))
		width -= i + 1;
	if (pflag->zero && !pflag->precision && !(num == '0' && i == 0))
		k = '0';
	while (width-- > 0)
		cnt += write(1, &k, 1);
	return (cnt);
}
