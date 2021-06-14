#include "ft_printf.h"

int	uns_int_printer(int len, char *str, t_fs fsp)
{
	int	qbw;

	qbw = 0;
	if (fsp.prec >= 0)
		qbw += print_width(fsp.prec, len, 1);
	qbw += print_with_prec(len, str);
	return (qbw);
}

int	get_uns_int(int len, char *str, t_fs fsp)
{
	int	qbw;

	qbw = 0;
	if (fsp.minus == 1)
		qbw += uns_int_printer(len, str, fsp);
	if (fsp.prec >= 0 && fsp.prec < len)
		fsp.prec = len;
	if (fsp.prec >= 0)
	{
		fsp.width -= fsp.prec;
		qbw += print_width(fsp.width, 0, 0);
	}
	else
		qbw += print_width(fsp.width, len, fsp.zero);
	if (fsp.minus == 0)
		qbw += uns_int_printer(len, str, fsp);
	return (qbw);
}

int	print_uns_int(unsigned int u, t_fs fsp)
{
	int		qbw;
	int		len;
	char	*str;

	qbw = 0;
	u = (unsigned int)(4294967295 + 1 + u);
	if (u == 0 && fsp.prec == 0)
		return (print_width(fsp.width, 0, 0));
	str = ft_itoa_long(u);
	len = ft_strlen(str);
	qbw += get_uns_int(len, str, fsp);
	free(str);
	return (qbw);
}
