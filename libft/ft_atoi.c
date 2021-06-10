#include "libft.h"

int	ft_atoi(const char *str)
{
	int		x;
	long	y;

	x = 1;
	y = 0;
	while (((*str > 8) && (*str < 14)) || *str == 32)
		str++;
	if (*str == 43 || *str == 45)
	{
		if (*str == 45)
			x = -x;
		str++;
	}
	if (*str < 48 || *str > 57)
		return (0);
	while ((*str > 47) && (*str < 58))
	{
		y = y * 10 + (*str - '0');
		if (y > 2147483647 && x == 1)
			return (-1);
		if (y > 2147483648 && x == -1)
			return (0);
		str++;
	}
	return (x * y);
}
