#include "ft_printf.h"

int	zero_ptr_print(t_fs flags)
{
	int		qbw;

	qbw = 0;
	if (flags.width >= 0 && flags.minus == 0)
	{
		qbw += print_width(flags.width, 2, 0);
		qbw += print_with_prec(2, "0x");
	}
	else
	{
		qbw += print_with_prec(2, "0x");
		qbw += print_width(flags.width, 2, 0);
	}
	return (qbw);
}

int	not_zero_ptr_print(int len, char *ptr, t_fs flags)
{
	int		qbw;

	qbw = 0;
	qbw += print_with_prec(2, "0x");
	if (flags.prec >= 0)
	{
		qbw += print_width(flags.prec, len, 1);
		qbw += print_with_prec(flags.prec, ptr);
	}
	else
		qbw += print_with_prec(len, ptr);
	return (qbw);
}
