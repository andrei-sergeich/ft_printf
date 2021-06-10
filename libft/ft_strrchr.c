#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		x;
	char	sb;

	x = 0;
	sb = (char)c;
	while (s[x])
		x++;
	while (x >= 0)
	{
		if (s[x] == sb)
			return ((char *)s + x);
		x--;
	}
	return (NULL);
}
