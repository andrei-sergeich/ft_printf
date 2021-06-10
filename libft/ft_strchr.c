#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		x;
	char	sb;

	x = 0;
	sb = (char)c;
	while (s[x])
	{
		if (s[x] == sb)
			return ((char *)s + x);
		x++;
	}
	if (s[x] == sb)
		return ((char *)s + x);
	return (NULL);
}
