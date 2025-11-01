#include <stdlib.h>

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return (1);
		i++;
	}
	if ((unsigned char)c == '\0' && s[i] == '\0')
		return (1);
	return (0);
}

int	list_size(const char *s, const char *charset)
{
	int	strings;
	int	i;

	i = 0;
	strings = 0;
	while (s[i])
	{
		while (s[i] && ft_strchr(charset, s[i]))
			i++;
		if (s[i] && !ft_strchr(charset, s[i]))
		{
			strings++;
			while (s[i] && !(ft_strchr(charset, s[i])))
				i++;
		}
	}
	return (strings);
}

int	ft_strlen_sep(const char *s, const char *charset)
{
	int	len;
	int	i;

	len = 0;
	while (s[len] && !(ft_strchr(charset, s[len])))
		len++;
	return (len);
}

char	*smoll_string(const char *s, const char *charset)
{
	char	*smoll;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen_sep(s, charset);
	smoll = malloc(len + 1);
	if (!smoll)
		return (NULL);
	smoll[len] = '\0';
	while ((s[i] && i < len + 1) && !ft_strchr(charset, s[i]))
	{
		smoll[i] = s[i];
		i++;
	}
	return (smoll);
}

char	**ft_split(const char *s, const char *charset)
{
	char	**list;
	int		i;
	int		j;
	char	str;

	if (!s || !charset)
		return (0);
	list = malloc((list_size(s, charset) + 1) * (sizeof(char *)));
	if (!list)
		return (0);
	while (*s)
	{
		while (*s && ft_strchr(charset, *s))
			s++;
		if (*s && !ft_strchr(charset, *s))
		{
			list[j++] = smoll_string(s, charset);
			if (!list[j - 1])
				return (0);
			while (*s && !(ft_strchr(charset, *s)))
				s++;
		}
	}
	list[j] = 0;
	return (list);
}

#include <stdio.h>

int	main(void)
{
	char	**list = ft_split("1h1h222", "01234");

	while (*list)
	{
		printf("%s\n", *list);
		list++;
	}
}
