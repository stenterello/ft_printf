#include "../includes/ft_printf.h"

char	*ft_get_hex(int data, char *base)
{
	char	*convert;
	char	*convert2;

	if ((data < 0 || data / ft_strlen(base) > 15) && data != -2147483648)
	{
		convert = ft_int_to_bin(data);
		convert2 = ft_reverse_bin(convert);
		convert2 = ft_add_one_to_bin(convert2, 31);
		convert2 = ft_bin_to_hex(convert2, base);
		free(convert);
	}
	else if (data == -2147483648)
		return ("80000000");
	else
		convert2 = ft_get_pos_hex(data, base);
	return (convert2);
}

char	*ft_get_pos_hex(int data, char *base)
{
	int		i;
	char	*ret;

	i = 0;
	ret = ft_calloc(19, sizeof(char));
	while (data > 15)
	{
		ret[i++] = base[data / ft_strlen(base)];
		data /= ft_strlen(base);
	}
	ret[i] = base[data % ft_strlen(base)];
	return (ret);
}

int	ft_hexnbrlen(unsigned int data)
{
	int		i;
	char	*convert;

	convert = ft_get_pos_hex(data, "0123456789abcdef");
	i = (int)ft_strlen(convert);
	free(convert);
	return (i);
}

int	ft_treat_hex(va_list args, t_print *arg)
{
	unsigned int	data;
	char			*convert;
	char			*base;
	char			*pr;
	int				i;

	i = 0;
	base = "0123456789abcdef";
	data = va_arg(args, unsigned int);
	convert = ft_get_hex(data, base);
	if (arg->minus && arg->width > (int)ft_strlen(convert))
	{
		data = ft_putnbr_u_base(data, base);
		while (data < (unsigned int)arg->width)
		{
			ft_putchar_fd(' ', 1);
			data++;
		}
	}
	else if (arg->zero && arg->width > (int)ft_strlen(convert))
	{
		while (i < arg->width - (int)ft_strlen(convert))
		{
			ft_putchar_fd('0', 1);
			i++;
		}
		data = ft_putnbr_u_base(data, base);
		data += i;
	}
	else if (arg->dot && arg->width > (int)ft_strlen(convert))
	{
		while (i < arg->width - (int)ft_strlen(convert))
		{
			ft_putchar_fd('0', 1);
			i++;
		}
		data = ft_putnbr_u_base(data, base);
		data += i;
	}
	else if (arg->width > (int)ft_strlen(convert))
	{
		pr = ft_calloc(arg->width - (int)ft_strlen(convert), sizeof(char));
		ft_memset(pr, ' ', arg->width - (int)ft_strlen(convert));
		ft_putstr_fd(pr, 1);
		data = ft_putnbr_u_base(data, base);
		data += ft_strlen(pr);
		free(pr);
	}
	else
		data = ft_putnbr_u_base(data, base);
	if (ft_strncmp(convert, "80000000", 9))
		free(convert);
	return (data);
}
