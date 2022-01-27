#include "../includes/ft_printf.h"

int	ft_treat_HEX(va_list args)
{
	int		data;
	char	*convert;
	char	*convert2;
	char	*base;

	base = "0123456789ABCDEF";
	data = va_arg(args, int);
	convert = NULL;
	convert2 = NULL;
	if (data < 0)
	{
		convert = ft_int_to_bin(data);
		convert2 = ft_reverse_bin(convert);
		convert2 = ft_add_one_to_bin(convert2, 31);
		data = ft_bin_to_hex(convert2, base);
		free(convert);
	}
	else
		data = ft_putnbr_base(data, base);
	return (data);
}