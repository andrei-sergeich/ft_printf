#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	x;

	x = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if ((start + len) > ft_strlen(s))
		str = (char *)malloc(sizeof(*s) * (ft_strlen(s) - start + 1));
	else
		str = (char *)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	while (x < len && s[start])
	{
		str[x] = s[start];
		x++;
		start++;
	}
	str[x] = '\0';
	return (str);
}
