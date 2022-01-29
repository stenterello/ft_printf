#include "../includes/ft_printf.h"

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
