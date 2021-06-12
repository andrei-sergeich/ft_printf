#include "ft_printf.h"

int	print_char(char x, t_fs fsp)
{
	int	qbw;

	qbw = 0;
	if (fsp.minus == 1)
		qbw += ft_putchar(x);
	qbw += print_width(fsp.width, 1, fsp.zero);
	if (fsp.minus == 0)
		qbw += ft_putchar(x);
	return (qbw);
}

int	strprinter(t_fs fsp, char *str, int len)
{
	int	qbw;

	qbw = 0;
	if (fsp.prec >= 0)
	{
		qbw += print_width(fsp.prec, len, 0);
		qbw += print_with_prec(fsp.prec, str);
	}
	else
		qbw += print_with_prec(len, str);
	return (qbw);
}

int	print_str(char *str, t_fs fsp)
{
	int	qbw;
	int	len;

	qbw = 0;
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (fsp.prec >= 0 && fsp.prec > len)
		fsp.prec = len;
	if (fsp.minus == 1)
		qbw += strprinter(fsp, str, len);
	if (fsp.prec >= 0)
		qbw += print_width(fsp.width, fsp.prec, 0);
	else
		qbw += print_width(fsp.width, len, 0);
	if (fsp.minus == 0)
		qbw += strprinter(fsp, str, len);
	return (qbw);
}
