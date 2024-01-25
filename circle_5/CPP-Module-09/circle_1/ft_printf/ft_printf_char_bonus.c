#include "ft_printf_bonus.h"

void	ft_printf_char(t_flag *pflag, char c, int *cnt)
{
	char	k;

	k = ' ';
	if (pflag->zero)
		k = '0';
	if (!pflag->minus)
	{
		while (--(pflag->width) > 0)
			(*cnt) += write(1, &k, 1);
	}
	if (!(pflag->dot && !pflag->precision))
		(*cnt) += write(1, &c, 1);
	while (--(pflag->width) > 0)
		(*cnt) += write(1, &k, 1);
}

void	ft_printf_str(t_flag *pflag, char *str, int *cnt)
{
	char	k;

	k = ' ';
	if (pflag->zero)
		k = '0';
	if (str == NULL)
		str = "(null)";
	if (pflag->precision && pflag->precision < (int)ft_strlen(str))
		pflag->width -= pflag->precision;
	else
		pflag->width -= ft_strlen(str);
	if (!pflag->minus)
	{
		while ((pflag->width)-- > 0)
			(*cnt) += write(1, &k, 1);
	}
	if (!(pflag->dot && !pflag->precision))
	{	
		if (pflag->precision && pflag->precision < (int)ft_strlen(str))
			(*cnt) += write(1, str, pflag->precision);
		else
			(*cnt) += write(1, str, ft_strlen(str));
	}
	while ((pflag->width)-- > 0)
		(*cnt) += write(1, &k, 1);
}
