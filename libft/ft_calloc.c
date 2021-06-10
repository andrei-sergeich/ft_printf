#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	x;

	x = 0;
	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (NULL);
	while (x < count * size)
	{
		ptr[x] = 0;
		x++;
	}
	return ((void *)ptr);
}
