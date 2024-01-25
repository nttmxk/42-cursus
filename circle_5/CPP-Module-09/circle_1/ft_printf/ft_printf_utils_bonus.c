#include "ft_printf_bonus.h"

int	ft_is_conversion(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd')
		return (1);
	if (c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

t_flag	*create_flag(void)
{
	t_flag	*pflag;

	pflag = (t_flag *)malloc(sizeof(t_flag));
	if (!pflag)
		return (NULL);
	pflag->minus = 0;
	pflag->plus = 0;
	pflag->zero = 0;
	pflag->hash = 0;
	pflag->space = 0;
	pflag->width = 0;
	pflag->dot = 0;
	pflag->precision = 0;
	return (pflag);
}
