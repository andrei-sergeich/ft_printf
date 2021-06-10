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
