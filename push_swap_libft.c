#include "push_swap.h"

static int		ft_find(const char *str, char c);
static int		ft_count(const char *str, char c);
static char		**ft_free(char **str, int size);
static char		**ft_split2(char const *s, char c);

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != (char)c)
		++i;
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	if (!s)
		return (NULL);
	return (ft_split2(s, c));
}

static char	**ft_split2(char const *s, char c)
{
	char	**ret;
	int		i;
	int		prev;
	int		next;

	ret = malloc((ft_count(s, c) + 1) * sizeof(char *));
	if (!ret)
		return (NULL);
	i = -1;
	prev = 0;
	while (s[prev])
	{
		next = ft_find(s + prev, c);
		if (next == 0)
		{
			++prev;
			continue ;
		}
		ret[++i] = ft_substr(s, prev, next);
		if (!ret[i])
			return (ft_free(ret, i));
		prev += next;
	}
	ret[++i] = NULL;
	return (ret);
}

static int	ft_count(const char *str, char c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			++cnt;
			while (str[i] && str[i] != c)
				++i;
		}
		else
			++i;
	}
	return (cnt);
}

static int	ft_find(const char *str, char c)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == c)
			return (i);
	return (i);
}

static char	**ft_free(char **str, int size)
{
	while (--size >= 0)
	{
		free(str[size]);
		str[size] = NULL;
	}
	free(str);
	str = NULL;
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ret;
	unsigned int	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s) || len == 0)
	{
		ret = malloc(sizeof(char));
		if (!ret)
			return (NULL);
		else
			ret[0] = 0;
		return (ret);
	}
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	ret = malloc((len + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	i = -1;
	while (++i < len && s[start + i])
		ret[i] = s[start + i];
	ret[i] = 0;
	return (ret);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}