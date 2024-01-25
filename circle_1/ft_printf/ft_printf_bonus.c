#include "ft_printf_bonus.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		cnt;

	cnt = 0;
	va_start(ap, fmt);
	ft_printf_2(fmt, &ap, &cnt);
	va_end(ap);
	return (cnt);
}

void	ft_printf_2(const char *fmt, va_list *ap, int *cnt)
{
	char	c;
	int		i;
	t_flag	*pflag;

	i = -1;
	while (fmt[++i])
	{
		c = fmt[i];
		if (c != '%')
			(*cnt) += write(1, &c, 1);
		else
		{
			pflag = create_flag();
			if (!pflag)
				return ;
			ft_set_flag(&fmt[i], pflag);
			while (fmt[++i] && !ft_is_conversion(fmt[i]))
				;
			ft_printf_parse(pflag, ap, fmt[i], cnt);
			free(pflag);
		}
	}
}

void	ft_set_flag(const char *fmt, t_flag *pflag)
{
	int	i;

	i = 0;
	while (fmt[++i] && !ft_is_conversion(fmt[i]))
	{
		if (fmt[i] == '.')
			pflag->dot = 1;
		else if (fmt[i] == '-')
			pflag->minus = 1;
		else if (fmt[i] == '+')
			pflag->plus = 1;
		else if (fmt[i] == '#')
			pflag->hash = 1;
		else if (fmt[i] == ' ')
			pflag->space = 1;
		else
		{
			if (fmt[i] == '0' && !pflag->width && !pflag->precision)
				pflag->zero = 1;
			else if (pflag->dot)
				pflag->precision = pflag->precision * 10 + (fmt[i] - '0');
			else
				pflag->width = pflag->width * 10 + (fmt[i] - '0');
		}
	}
}

void	ft_printf_parse(t_flag *pflag, va_list *ap, char c, int *cnt)
{
	if (c == 'c')
		ft_printf_char(pflag, va_arg(*ap, int), cnt);
	else if (c == 's')
		ft_printf_str(pflag, va_arg(*ap, char *), cnt);
	else if (c == 'p')
		ft_printf_hexa(pflag, va_arg(*ap, unsigned long long), 2, cnt);
	else if (c == 'd' || c == 'i')
		ft_printf_int(pflag, va_arg(*ap, int), cnt);
	else if (c == 'u')
		ft_printf_uint(pflag, va_arg(*ap, unsigned int), cnt);
	else if (c == 'x')
		ft_printf_hexa(pflag, va_arg(*ap, unsigned int), 0, cnt);
	else if (c == 'X')
		ft_printf_hexa(pflag, va_arg(*ap, unsigned int), 1, cnt);
	else
		ft_printf_percent(cnt);
}

void	ft_printf_percent(int *cnt)
{
	(*cnt) += write(1, "%", 1);
}
