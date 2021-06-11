#include "ft_printf.h"

char	*ptr_to_str(unsigned long long tmp, int bt, char *str, t_fs flags)
{
	bt--;
	while (tmp != 0)
	{
		if ((tmp % flags.base) < 10)
			str[bt] = (tmp % flags.base) + 48;
		else
			str[bt] = (tmp % flags.base) + 87;
		tmp /= flags.base;
		bt--;
	}
	return (str);
}

int	ptr_printer(int qbw, int len, char *ptr, t_fs flags)
{
	if (flags.prec < len)
		flags.prec = len;
	if (flags.minus == 1 && flags.prec <= 0)
	{
		qbw += not_zero_ptr_print(len, ptr, flags);
		qbw += print_width(flags.width, len + 2, 0);
	}
	if (flags.minus == 1 && flags.prec > 0)
	{
		qbw += not_zero_ptr_print(len, ptr, flags);
		qbw += print_width(flags.width, flags.prec + 2, 0);
	}
	if (flags.minus == 0 && flags.prec > 0)
	{
		qbw += print_width(flags.width, flags.prec + 2, 0);
		qbw += not_zero_ptr_print(len, ptr, flags);
	}
	if (flags.minus == 0 && flags.prec <= 0)
	{
		qbw += print_width(flags.width, len + 2, 0);
		qbw += not_zero_ptr_print(len, ptr, flags);
	}
	return (qbw);
}

char	*ptr_processing(unsigned long long p, t_fs flags)
{
	unsigned long long	tmp;
	char				*str;
	int					bt;

	bt = 0;
	str = 0;
	tmp = p;
	if (p == 0)
		return (ft_strdup("0"));
	while (p != 0)
	{
		p /= flags.base;
		bt++;
	}
	str = (char *)malloc(sizeof(char) * (bt + 1));
	if (!str)
		return (0);
	str[bt] = '\0';
	str = ptr_to_str(tmp, bt, str, flags);
	return (str);
}

int	print_ptr(unsigned long long p, t_fs flags)
{
	int		qbw;
	int		len;
	char	*ptr;

	qbw = 0;
	if (p == 0 && flags.prec == 0)
		return (zero_ptr_print(flags));
	ptr = ptr_processing(p, flags);
	len = ft_strlen(ptr);
	qbw += ptr_printer(qbw, len, ptr, flags);
	free(ptr);
	return (qbw);
}
