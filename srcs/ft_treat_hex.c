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
	int		data;
	char	*convert;
	char	*base;
	char	*pr;

	base = "0123456789abcdef";
	data = va_arg(args, unsigned int);
	convert = ft_get_hex(data, base);
	if (arg->width > ft_strlen(convert))
	{
		pr = ft_calloc(ft_strlen(convert), sizeof(char));
		ft_memset(pr, ' ', ft_strlen(convert));
		ft_strlcpy(&pr[arg->width - ft_strlen(convert)], convert, ft_strlen(convert) + 1);
		ft_putstr_fd(pr, 1);
		data = ft_strlen(pr);
		free(pr);
		return (data);
	}
	else
	{
		if (data < 0)
		{

			ft_putstr_fd(convert, 1);
			data = ft_strlen(convert);
			free(convert);
		}
		else
			data = ft_putnbr_base(data, base);
	}
	return (data);
}
