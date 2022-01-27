#include "../includes/ft_printf.h"

int	ft_int_nbrlen(int n)
{
	int	i;

	i = 1;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	ft_treat_d(va_list args, t_print *arg)
{
	int		data;
	char	*ret;
	char	*data2;
	int		ret2;
	int		len;

	data = (int)va_arg(args, int);
	len = 0;
	if (arg->flags)
	{
		if (arg->minus && arg->width > ft_int_nbrlen(data))
		{
			ret = ft_calloc(sizeof(char), (arg->width + 2));
			ft_memset(ret, ' ', arg->width);
			data2 = ft_itoa(data);
			ft_strlcpy(ret, data2, ft_strlen(data2) + 1);
			ret[ft_strlen(data2)] = ' ';
			ret[arg->width] = '\0';
			free(data2);
			ft_putstr_fd(ret, 1);
			free(ret);
			return (arg->width);
		}
		else if ((arg->zero || arg->dot) && arg->width > ft_int_nbrlen(data))
		{
			ret = ft_calloc(sizeof(char), (arg->width + 1));
			ft_memset(ret, 48, arg->width);
			data2 = ft_itoa(data);
			len = ft_strlen(data2);
			ft_strlcpy(&ret[arg->width - len], data2, len + 1);
			ret[arg->width] = '\0';
			free(data2);
			ft_putstr_fd(ret, 1);
			free(ret);
			return (arg->width);
		}
		else if ((arg->hash || arg->space) && arg->width > ft_int_nbrlen(data))
		{
			ret = ft_calloc(sizeof(char), (arg->width + 1));
			ft_memset(ret, ' ', arg->width);
			data2 = ft_itoa(data);
			len = ft_strlen(data2);
			ft_strlcpy(&ret[arg->width - len], data2, len + 1);
			ret[len] = ' ';
			ret[arg->width] = '\0';
			free(data2);
			ft_putstr_fd(ret, 1);
			free(ret);
			return (arg->width);
		}
		else if (arg->space)
		{
			ft_putchar_fd(' ', 1);
			data2 = ft_itoa(data);
			ft_putstr_fd(data2, 1);
			free(data2);
			return (ft_int_nbrlen(data) + 1);
		}
		else if (arg->plus && !arg->width)
		{
			if (data > 0)
			{
				ft_putchar_fd('+', 1);
				len = 1;
			}
			data2 = ft_itoa(data);
			ft_putstr_fd(data2, 1);
			len += ft_strlen(data2);
			free(data2);
			return (len);
		}
		else if (arg->plus && arg->width)
		{
			ret = ft_calloc(sizeof(char), (arg->width + 1));
			ft_memset(ret, ' ', arg->width);
			data2 = ft_itoa(data);
			len = ft_strlen(data2);
			ft_strlcpy(&ret[arg->width - len], data2, len + 1);
			ret[len] = ' ';
			ret[arg->width] = '\0';
			if (data > 0)
				ret[arg->width - len - 1] = '+';
			free(data2);
			ft_putstr_fd(ret, 1);
			free(ret);
			return (arg->width);
		}
		else if (arg->width > ft_int_nbrlen(data))
		{
			ret = ft_calloc(sizeof(char), (arg->width + 2));
			ft_memset(ret, ' ', arg->width);
			data2 = ft_itoa(data);
			ft_strlcpy(&ret[arg->width - ft_strlen(data2)], data2, ft_strlen(data2) + 1);
			ret[arg->width] = '\0';
			free(data2);
			ft_putstr_fd(ret, 1);
			free(ret);
			return (arg->width);
		}
		else
		{
			ft_putnbr_fd(data, 1);
			ret = ft_itoa(data);
			ret2 = ft_strlen(ret);
			free(ret);
		}
	}
	else
	{
		ft_putnbr_fd(data, 1);
		ret = ft_itoa(data);
		ret2 = ft_strlen(ret);
		free(ret);
	}
	return (ret2);
}
