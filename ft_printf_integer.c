#include "ft_printf.h"

int	integerprinter(char *str, int tmp, t_fs flags)
{
	int	qbw;

	qbw = 0;
	if (tmp < 0 && flags.prec >= 0)
		qbw += ft_putchar('-');
	if (flags.prec >= 0)
		qbw += print_width(flags.prec, ft_strlen(str), 1);
	qbw += print_with_prec(ft_strlen(str), str);
	return (qbw);
}

int	get_integer(char *str, int tmp, t_fs flags)
{
	int	qbw;

	qbw = 0;
	if (flags.minus == 1)
		qbw += integerprinter(str, tmp, flags);
	if (flags.prec >= 0 && (size_t)flags.prec < ft_strlen(str))
		flags.prec = ft_strlen(str);
	if (flags.prec >= 0)
	{
		flags.width -= flags.prec;
		qbw += print_width(flags.width, 0, 0);
	}
	else
		qbw += print_width(flags.width, ft_strlen(str), flags.zero);
	if (flags.minus == 0)
		qbw += integerprinter(str, tmp, flags);
	return (qbw);
}

int	print_integer(int d, t_fs flags)
{
	int		qbw;
	int		tmp;
	char	*str;

	qbw = 0;
	tmp = d;
	if (d == 0 && flags.prec == 0)
		return (print_width(flags.width, 0, 0));
	if (d < 0 && (flags.prec >= 0 || flags.zero == 1))
	{
		if (flags.zero == 1 && flags.prec == -1)
			qbw += ft_putchar('-');
		flags.width--;
		d = -d;
		if (flags.prec >= 0)
			flags.zero = 1;
	}
	if (d == -2147483648)
		str = ft_strdup("2147483648");
	else
		str = ft_itoa(d);
	qbw += get_integer(str, tmp, flags);
	free(str);
	return (qbw);
}
