#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t l)
{
	size_t	x;

	x = 0;
	if (!dst && !src)
		return (0);
	while (x < l)
	{
		*((char *)dst + x) = *((const char *)src + x);
		x++;
	}
	return (dst);
}
