#include <stdlib.h>

int		ft_strlen(char *str);
int		char_to_val(char c, char *base);
int		get_len(long n, int base_len);
long	ft_atoi_base(char *str, char *base);
char	*ft_putnbr_base_malloc(long n, char *base);
int		is_valid_base(char *base);

int	is_valid_base(char *base)
{
	int	i;
	int	j;

	if (!base || ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || (base[i] >= 9 && base[i] <= 13)
			|| base[i] == ' ')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

long	ft_atoi_base(char *str, char *base)
{
	long	num;
	int		val;
	int		i;
	int		sign;
	int		base_len;

	i = 0;
	sign = 1;
	num = 0;
	base_len = ft_strlen(base);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -sign;
	val = char_to_val(str[i], base);
	while (val != -1)
	{
		num = num * base_len + val;
		i++;
		val = char_to_val(str[i], base);
	}
	return (num * sign);
}

char	*ft_putnbr_base_malloc(long n, char *base)
{
	int		base_len;
	int		len;
	char	*res;
	long	nb;

	base_len = ft_strlen(base);
	len = get_len(n, base_len);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	res[len] = '\0';
	nb = n;
	if (nb < 0)
	{
		res[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		res[0] = base[0];
	while (nb)
	{
		res[--len] = base[nb % base_len];
		nb /= base_len;
	}
	return (res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	num;

	if (!is_valid_base(base_from) || !is_valid_base(base_to))
		return (NULL);
	num = ft_atoi_base(nbr, base_from);
	return (ft_putnbr_base_malloc(num, base_to));
}

// #include <stdio.h>
// #include <stdlib.h>

// char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

// int	main(void)
// {
// 	char	*res;

// 	res = ft_convert_base("101", "01", "0123456789");
// 	printf("%s\n", res);
// 	free(res);
// 	res = ft_convert_base("-42", "0123456789", "01");
// 	printf("%s\n", res);
// 	free(res);
// 	res = ft_convert_base("2A", "0123456789ABCDEF", "01");
// 	printf("%s\n", res);
// 	free(res);
// 	res = ft_convert_base("poney", "poneyvif", "0123456789");
// 	printf("%s\n", res);
// 	free(res);
// 	res = ft_convert_base("invalid", "01", "0123456789");
// 	if (!res)
// 		printf("NULL\n");
// 	return (0);
// }
