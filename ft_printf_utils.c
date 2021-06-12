#include "ft_printf.h"

int	ft_putchar(char x)
{
	write(1, &x, 1);
	return (1);
}

int	print_width(int wd, int mn, int zr)
{
	int	qbw;

	qbw = 0;
	while (wd - mn > 0)
	{
		if (zr)
			ft_putchar('0');
		else
			ft_putchar(' ');
		wd--;
		qbw++;
	}
	return (qbw);
}

int	print_with_prec(int prec, char *str)
{
	int	qbw;

	qbw = 0;
	while (str[qbw] && qbw < prec)
	{
		ft_putchar(str[qbw]);
		qbw++;
	}
	return (qbw);
}

char	*convers_to_str(unsigned long long tmp, int bt, char *str, t_fs flags)
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

char	*nbr_processing(unsigned long long p, t_fs flags)
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
	str = convers_to_str(tmp, bt, str, flags);
	return (str);
}
