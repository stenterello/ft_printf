#include "../includes/ft_printf.h"

int	ft_treat_HEX(va_list args, t_print *arg)
{
	unsigned int	data;
	char			*convert;
	char			*base;
	char			*pr;
	int				i;

	i = 0;
	base = "0123456789ABCDEF";
	data = va_arg(args, unsigned int);
	convert = ft_get_hex(data, base);
	if (arg->minus && arg->width > ft_u_base_len(data, base))
	{
		data = ft_putnbr_u_base(data, base);
		while (data < (unsigned int)arg->width)
		{
			ft_putchar_fd(' ', 1);
			data++;
		}
	}
	else if (arg->zero && arg->width > ft_u_base_len(data, base))
	{
		while (i < arg->width - ft_u_base_len(data, base))
		{
			ft_putchar_fd('0', 1);
			i++;
		}
		data = ft_putnbr_u_base(data, base);
		data += i;
	}
	else if (arg->dot && arg->prec > ft_u_base_len(data, base))
	{
		while (i < arg->prec - ft_u_base_len(data, base))
		{
			ft_putchar_fd('0', 1);
			i++;
		}
		data = ft_putnbr_u_base(data, base);
		data += i;
	}
	else if (arg->dot && !arg->prec && data == 0)
	{
		free(convert);
		return (0);
	}
	else if (arg->width > ft_u_base_len(data, base))
	{
		pr = ft_calloc(arg->width - ft_u_base_len(data, base), sizeof(char));
		ft_memset(pr, ' ', arg->width - ft_u_base_len(data, base));
		ft_putstr_fd(pr, 1);
		data = ft_putnbr_u_base(data, base);
		data += ft_strlen(pr);
		free(pr);
	}
	else
	{
		if (arg->hash && data != 0)
		{
			ft_putstr_fd("0X", 1);
			data = ft_putnbr_u_base(data, base) + 2;
		}
		else
			data = ft_putnbr_u_base(data, base);
	}
	if (ft_strncmp(convert, "80000000", 9))
		free(convert);
	return (data);
}
