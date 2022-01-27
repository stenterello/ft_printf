#include "../includes/ft_printf.h"

// char	*ft_utoa(unsigned int n)
// {
// 	char	*str;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = ft_unbrlen(n);
// 	str = malloc(sizeof(char) * (j + 1));
// 	if (!str)
// 		return (NULL);
// 	while (n > 9)
// 	{
// 		str[i++] = n / (ft_power(10, (j - 1))) + 48;
// 		n /= 10;
// 	}
// 	str[i] = n % 10 + 48;
// 	str[i + 1] = '\0';
// 	return (str);
// }

void	ft_putnbr(long n, char *str, int *i)
{
	if (n > 9)
	{
		ft_putnbr(n / 10, str, i);
		ft_putnbr(n % 10, str, i);
	}
	else
		str[(*i)++] = n + '0';
}

char	*ft_utoa(unsigned int n)
{
	char	*str;
	int		i;
	long	nbr;

	nbr = n;
	str = ft_calloc(sizeof(char), (ft_unbrlen(nbr) + 1));
	if (!str)
		return (NULL);
	i = 0;
	ft_putnbr(nbr, str, &i);
	str[i] = '\0';
	return (str);
}

int	ft_unbrlen(unsigned int n)
{
	int	i;

	i = 1;
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	ft_putnbr_u_fd(unsigned int n, int fd)
{
	int		count;
	char	*data;

	data = ft_utoa(n);
	count = ft_strlen(data);
	free(data);
	if (n > 9)
	{
		ft_putnbr_u_fd(n / 10, fd);
		ft_putnbr_u_fd(n % 10, fd);
	}
	else
		ft_putchar_fd(n + 48, fd);
	return (count);
}
