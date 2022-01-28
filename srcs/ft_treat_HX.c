#include "../includes/ft_printf.h"

int	ft_treat_HEX(va_list args, t_print *arg)
{
	int		data;
	char	*convert;
	char	*base;
	char	*pr;

	base = "0123456789ABCDEF";
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
