#include "libft.h"

void	ft_bzero(void *s, size_t x)
{
	size_t	z;

	z = 0;
	while (z < x)
	{
		*((unsigned char *)s + z) = 0;
		z++;
	}
}
