#include "ft_printf.h"

int	hex_printer(int len, char *str, t_fs fsp)
{
	int	qbw;

	qbw = 0;
	if (fsp.prec >= 0)
		qbw += print_width(fsp.prec, len, 1);
	qbw += print_with_prec(len, str);
	return (qbw);
}

int	get_hex(int len, char *str, t_fs fsp)
{
	int	qbw;

	qbw = 0;
	if (fsp.minus == 1)
		qbw += hex_printer(len, str, fsp);
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
		qbw += hex_printer(len, str, fsp);
	return (qbw);
}

int	print_hex(unsigned int hex, t_fs fsp)
{
	int		z;
	int		len;
	int		qbw;
	char	*str;

	z = 0;
	qbw = 0;
	hex = (unsigned int)(4294967295 + 1 + hex);
	if (hex == 0 && fsp.prec == 0)
		return (print_width(fsp.width, 0, 0));
	str = nbr_processing((unsigned long long)hex, fsp);
	if (fsp.hexup)
	{
		while (str[z])
		{
			str[z] = ft_toupper(str[z]);
			z++;
		}
	}
	len = ft_strlen(str);
	qbw += get_hex(len, str, fsp);
	free(str);
	return (qbw);
}
