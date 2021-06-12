#include "ft_printf.h"

int	zero_ptr_print(t_fs fsp)
{
	int	qbw;

	qbw = 0;
	if (fsp.width >= 0 && fsp.minus == 0)
	{
		qbw += print_width(fsp.width, 2, 0);
		qbw += print_with_prec(2, "0x");
	}
	else
	{
		qbw += print_with_prec(2, "0x");
		qbw += print_width(fsp.width, 2, 0);
	}
	return (qbw);
}

int	not_zero_ptr_print(int len, char *ptr, t_fs fsp)
{
	int	qbw;

	qbw = 0;
	qbw += print_with_prec(2, "0x");
	if (fsp.prec >= 0)
	{
		qbw += print_width(fsp.prec, len, 1);
		qbw += print_with_prec(fsp.prec, ptr);
	}
	else
		qbw += print_with_prec(len, ptr);
	return (qbw);
}

int	ptr_printer(int qbw, int len, char *ptr, t_fs fsp)
{
	if (fsp.prec < len)
		fsp.prec = len;
	if (fsp.minus == 1 && fsp.prec <= 0)
	{
		qbw += not_zero_ptr_print(len, ptr, fsp);
		qbw += print_width(fsp.width, len + 2, 0);
	}
	if (fsp.minus == 1 && fsp.prec > 0)
	{
		qbw += not_zero_ptr_print(len, ptr, fsp);
		qbw += print_width(fsp.width, fsp.prec + 2, 0);
	}
	if (fsp.minus == 0 && fsp.prec > 0)
	{
		qbw += print_width(fsp.width, fsp.prec + 2, 0);
		qbw += not_zero_ptr_print(len, ptr, fsp);
	}
	if (fsp.minus == 0 && fsp.prec <= 0)
	{
		qbw += print_width(fsp.width, len + 2, 0);
		qbw += not_zero_ptr_print(len, ptr, fsp);
	}
	return (qbw);
}

int	print_ptr(unsigned long long p, t_fs fsp)
{
	int		qbw;
	int		len;
	char	*ptr;

	qbw = 0;
	if (p == 0 && fsp.prec == 0)
		return (zero_ptr_print(fsp));
	ptr = nbr_processing(p, fsp);
	len = ft_strlen(ptr);
	qbw += ptr_printer(qbw, len, ptr, fsp);
	free(ptr);
	return (qbw);
}
