#include "../includes/ft_printf.h"

int	ft_treat_c(va_list args, t_print *arg)
{
	char	*data;
	char	c;
	int		i;

	i = 0;
	if (arg->width && arg->flags)
	{
		data = malloc(sizeof(char) * (arg->width + 1));
		if (arg->minus)
		{
			ft_memset(data, ' ', arg->width);
			data[0] = (char)va_arg(args, int);
			data[arg->width] = '\0';
			while (i < arg->width)
				ft_putchar_fd(data[i++], 1);
		}
		else if (arg->zero)
		{
			ft_memset(data, 48, arg->width);
			data[arg->width - 1] = (char)va_arg(args, int);
			data[arg->width] = '\0';
			ft_putstr_fd(data, 1);
		}
		else if (arg->hash || arg->space)
		{
			ft_memset(data, 32, arg->width);
			data[arg->width - 1] = (char)va_arg(args, int);
			data[arg->width] = '\0';
			ft_putstr_fd(data, 1);
		}
		else if (arg->width)
		{
			ft_memset(data, 32, arg->width);
			data[arg->width - 1] = (char)va_arg(args, int);
			data[arg->width] = '\0';
			ft_putstr_fd(data, 1);
			if (data[arg->width - 1] == '\0')
				ft_putchar_fd('\0', 1);
		}
		else
		{
			c = (char)va_arg(args, int);
			ft_putchar_fd(c, 1);
			if (data[arg->width - 1] == '\0')
				ft_putchar_fd('\0', 1);
		}
		free(data);
		return (arg->width);
	}
	else
	{
		c = (char)va_arg(args, int);
		ft_putchar_fd(c, 1);
	}
	return (1);
}
