#include "../includes/ft_printf.h"

char	*ft_get_hex(int data, char *base)
{
	char	*convert;
	char	*convert2;

	convert = ft_int_to_bin(data);
	convert2 = ft_reverse_bin(convert);
	convert2 = ft_add_one_to_bin(convert2, 31);
	convert2 = ft_bin_to_hex(convert2, base);
	free(convert);
	return (convert2);
}

int	ft_treat_hex(va_list args, t_print *arg)
{
	unsigned int	data;
	char			*convert;
	char			*base;
	char			*pr;

	base = "0123456789abcdef";
	data = va_arg(args, unsigned int);
	convert = ft_get_hex(data, base);
	if (arg->minus && arg->width > ft_unbrlen(data))
	{
		data = ft_putnbr_u_base(data, base);
		while (data < (unsigned int)arg->width)
		{
			ft_putchar_fd(' ', 1);
			data++;
		}
	}
	else if (arg->width > ft_unbrlen(data))
	{
		pr = ft_calloc(arg->width - ft_unbrlen(data), sizeof(char));
		ft_memset(pr, ' ', arg->width - ft_unbrlen(data));
		ft_putstr_fd(pr, 1);
		data = ft_putnbr_u_base(data, base);
		data += ft_strlen(pr);
		free(pr);
	}
	else
		data = ft_putnbr_u_base(data, base);
	free(convert);
	return (data);
}
