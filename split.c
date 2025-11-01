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
	return count ; 
}
void	copystring(char *str, char **ptr, int index, int start, int end)
{
	int	j;

	j = 0;
	while (start < end)
	{
		ptr[index][j] = str[start];
		start++;
		j++;
	}
	ptr[index][end] = '\0';
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
		while (!check(str[start], charset) && str[start])
			start++;
		while (check(str[end], charset) && str[end])
			end++;
		ptr[index] = malloc(end - start + 1);
		copystring(str, ptr, index, start, end);
		start = end;
		index++;
	}
}
char	**ft_split(char *str, char *charset)
{
	int numofstrings;
	char **ptr;
	numofstrings = countstrings(str, charset);
	ptr = malloc((numofstrings + 1) * sizeof(char *));
	ptr[numofstrings] = NULL;
	smallallocate(numofstrings,str, charset, ptr);
	return (ptr);
}
int main () {
char *c ; 
char *arr ;
char **n ; 
c="ji" ; 
arr = "mewojhiiijps" ;
n = ft_split(arr , c) ; 
printf("%s" , n[0]);
printf("%s" , n[1]) ; 
}

