#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool	check(char c, char *charset)
{
	int	index;

	index = 0;
	while (charset[index])
	{
		if (charset[index] == c)
			return (false);
		index++;
	}
	return (true);
}

int	countstrings(char *str, char *charset)
{
	int		index;
	int		count;
	bool	flag;

	flag = true;
	index = 0;
	count = 0;
	while (str[index])
	{
		if (check(str[index], charset))
		{
			if (flag)
				count++;
			flag = false;
		}
		else
			flag = true;
		index++;
	}
	return (count);
}

char	*copystring(char *str, char **ptr, int start, int end)
{
	int		j;
	char	*new_string;

	new_string = malloc(end - start + 1);
	if (!new_string)
		return (NULL);
	j = 0;
	while (start < end)
	{
		new_string[j] = str[start];
		start++;
		j++;
	}
	new_string[j] = '\0';
	return (new_string);
}

void	smallallocate(int numofstrings, char *str, char *charset, char **ptr)
{
	int	index;
	int	start;
	int	end;

	start = 0;
	end = 0;
	index = 0;
	while (index < numofstrings)
	{
		while (str[start] && !check(str[start], charset))
			start++;
		end = start;
		while (str[end] && check(str[end], charset))
			end++;
		ptr[index] = copystring(str, ptr, start, end);
		start = end;
		index++;
	}
}

char	**ft_split(char *str, char *charset)
{
	int		numofstrings;
	char	**ptr;

	numofstrings = countstrings(str, charset);
	ptr = malloc((numofstrings + 1) * sizeof(char *));
	ptr[numofstrings] = NULL;
	smallallocate(numofstrings, str, charset, ptr);
	return (ptr);
}

// int	main(void)
// {
// 	char	**n;

// 	printf("%d\n", countstrings("meow111meow222meow333", "123"));
// 	n = ft_split("meow111meow222meow333", "123");
// 	while (*n)
// 	{
// 		printf("%s\n", *n);
// 		n++;
// 	}
// }
