#include "libft.h"

void	*ft_memset(void *str, int x, size_t len)
{
	size_t			z;
	unsigned char	*nstr;

	z = 0;
	nstr = (unsigned char *)str;
	while (z < len)
	{
		nstr[z] = (unsigned char)x;
		z++;
	}
	return (str);
}
