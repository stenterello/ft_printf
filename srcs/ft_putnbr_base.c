#include "../includes/ft_printf.h"

int	ft_putnbr_base(int nbr, char *base)
{
	long	i;

	i = 0;
	if (nbr / (int)(ft_strlen(base)) > 0)
	{
		i += ft_putnbr_base((nbr / (int)(ft_strlen(base))), base);
		i += ft_putnbr_base((nbr % (int)(ft_strlen(base))), base);
	}
	else
	{
		ft_putchar_fd(base[nbr % (ft_strlen(base))], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr_base_ptr(size_t nbr, char *base)
{
	int	i;

	i = 0;
	if (nbr / ft_strlen(base) > 0)
	{
		i += ft_putnbr_base_ptr((nbr / ft_strlen(base)), base);
		i += ft_putnbr_base_ptr((nbr % ft_strlen(base)), base);
	}
	else
	{
		ft_putchar_fd(base[nbr % (ft_strlen(base))], 1);
		i++;
	}
	return (i);
}