#include "ft_printf.h"

int	ft_isflag(int x)
{
	if (x == '-' || x == '0' || x == '.' || x == '*')
		return (1);
	else
		return (0);
}

int	ft_istype(int x)
{
	if (x == 'c' || x == 's' || x == 'p' || x == 'd' || x == 'i' || x == 'u'
		|| x == 'x' || x == 'X' || x == '%')
		return (1);
	else
		return (0);
}
