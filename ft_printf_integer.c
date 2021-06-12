#include "ft_printf.h"

int	integerprinter(char *str, int tmp, t_fs fsp)
{
	int	qbw;

	qbw = 0;
	if (tmp < 0 && (fsp.prec >= 0 && tmp != -2147483648))
		qbw += ft_putchar('-');
	if (fsp.prec >= 0)
		qbw += print_width(fsp.prec, ft_strlen(str), 1);
	qbw += print_with_prec(ft_strlen(str), str);
	return (qbw);
}

int	get_integer(char *str, int tmp, t_fs fsp)
{
	int	qbw;

	qbw = 0;
	if (fsp.minus == 1)
		qbw += integerprinter(str, tmp, fsp);
	if (fsp.prec >= 0 && (size_t)fsp.prec < ft_strlen(str))
		fsp.prec = ft_strlen(str);
	if (fsp.prec >= 0)
	{
		fsp.width -= fsp.prec;
		qbw += print_width(fsp.width, 0, 0);
	}
	else
		qbw += print_width(fsp.width, ft_strlen(str), fsp.zero);
	if (fsp.minus == 0)
		qbw += integerprinter(str, tmp, fsp);
	return (qbw);
}

int	print_integer(int d, t_fs fsp)
{
	int		qbw;
	int		tmp;
	char	*str;

	qbw = 0;
	tmp = d;
	if (d == 0 && fsp.prec == 0)
		return (print_width(fsp.width, 0, 0));
	if (d < 0 && (fsp.prec >= 0 || fsp.zero == 1))
	{	
		if (fsp.zero == 1 && fsp.prec <= -1)
			qbw += ft_putchar('-');
		if (d != -2147483648)
			fsp.width--;
		d = -d;
		if (fsp.prec >= 0)
			fsp.zero = 1;
	}
	str = ft_itoa(d);
	qbw += get_integer(str, tmp, fsp);
	free(str);
	return (qbw);
}
