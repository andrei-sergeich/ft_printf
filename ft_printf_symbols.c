#include "ft_printf.h"

int	print_char(char x, t_fs flags)
{
	int	qbw;

	qbw = 0;
	if (flags.minus == 1)
		qbw += ft_putchar(x);
	qbw += print_width(flags.width, 1, flags.zero);
	if (flags.minus == 0)
		qbw += ft_putchar(x);
	return (qbw);
}

int	strprinter(t_fs flags, char *str)
{
	int	qbw;

	qbw = 0;
	if (flags.prec >= 0)
	{
		qbw += print_width(flags.prec, ft_strlen(str), 0);
		qbw += print_with_prec(flags.prec, str);
	}
	else
		qbw += print_with_prec(ft_strlen(str), str);
	return (qbw);
}

int	print_str(char *str, t_fs flags)
{
	int	qbw;

	qbw = 0;
	if (!str)
		str = "(null)";
	if (flags.prec >= 0 && (size_t)flags.prec > ft_strlen(str))
		flags.prec = ft_strlen(str);
	if (flags.minus == 1)
		qbw += strprinter(flags, str);
	if (flags.prec >= 0)
		qbw += print_width(flags.width, flags.prec, 0);
	else
		qbw += print_width(flags.width, ft_strlen(str), 0);
	if (flags.minus == 0)
		qbw += strprinter(flags, str);
	return (qbw);
}
