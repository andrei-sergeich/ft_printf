#include "ft_printf.h"

int	uns_int_printer(char *str, t_fs flags)
{
	int	qbw;

	qbw = 0;
	if (flags.prec >= 0)
		qbw += print_width(flags.prec, ft_strlen(str), 1);
	qbw += print_with_prec(ft_strlen(str), str);
	return (qbw);
}

int	get_uns_int(char *str, t_fs flags)
{
	int	qbw;

	qbw = 0;
	if (flags.minus == 1)
		qbw += uns_int_printer(str, flags);
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
		qbw += uns_int_printer(str, flags);
	return (qbw);
}

int	print_uns_int(unsigned int u, t_fs flags)
{
	int		qbw;
	char	*str;

	qbw = 0;
	u = (unsigned int)(4294967295 + 1 + u);
	if (u == 0 && flags.prec == 0)
		return (print_width(flags.width, 0, 0));
	str = ft_itoa_ui(u);
	qbw += get_uns_int(str, flags);
	free(str);
	return (qbw);
}
