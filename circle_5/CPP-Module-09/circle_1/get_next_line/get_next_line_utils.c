#include "get_next_line.h"

char	*ft_substr(char const *s, size_t len)
{
	char			*ret;
	unsigned int	i;

	if (!s || len == 0)
		return (NULL);
	ret = malloc((len + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	i = -1;
	while (++i < len && s[i])
		ret[i] = s[i];
	ret[i] = 0;
	return (ret);
}

int	ft_strchr(const char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		++i;
	if (s[i] == '\n')
		return (i);
	return (-1);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *) dest)[i] = ((unsigned char *) src)[i];
		++i;
	}
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

char	*ft_strjoin(char *s1, char const *s2) // buf('\0') should be modified.
{
	size_t	len;
	size_t	a;
	size_t	i;
	char	*ret;

	if (!s1)
		return (ft_substr(s2, ft_strlen(s2)));
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	ret = malloc(len * sizeof(char));
	if (!ret)
		return (NULL);
	i = -1;
	while (s1[++i])
		ret[i] = s1[i];
	a = i;
	free(s1); // modified
	s1 = NULL;
	i = -1;
	while (s2[++i])
		ret[a + i] = s2[i];
	ret[a + i] = 0;
	return (ret);
}