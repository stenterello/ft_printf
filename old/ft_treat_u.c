#include "../includes/ft_printf.h"

int	ft_treat_u(va_list args, t_print *arg)
{
	unsigned int	data;
	char			*ret;
	char			*data2;
	int				ret2;
	int				len;

	data = (unsigned int)va_arg(args, unsigned int);
	len = 0;
	if (arg->flags)
	{
		if (arg->minus && arg->width > ft_unbrlen(data))
		{
			ret = ft_calloc(sizeof(char), (arg->width + 3));
			ft_memset(ret, ' ', arg->width);
			data2 = ft_utoa(data);
			ft_strlcpy(ret, data2, ft_strlen(data2) + 1);
			ret[ft_strlen(data2)] = ' ';
			ret[arg->width] = '\0';
			free(data2);
			ft_putstr_fd(ret, 1);
			free(ret);
			return (arg->width);
		}
		else if ((arg->zero || arg->dot) && arg->width > ft_unbrlen(data))
		{
			ret = ft_calloc(sizeof(char), (arg->width + 1));
			ft_memset(ret, 48, arg->width);
			data2 = ft_utoa(data);
			len = ft_strlen(data2);
			ft_strlcpy(&ret[arg->width - len], data2, len + 1);
			ret[arg->width] = '\0';
			free(data2);
			ft_putstr_fd(ret, 1);
			free(ret);
			return (arg->width);
		}
		else if ((arg->hash || arg->space) && arg->width > ft_unbrlen(data))
		{
			ret = ft_calloc(sizeof(char), (arg->width + 1));
			ft_memset(ret, ' ', arg->width);
			data2 = ft_utoa(data);
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
			data2 = ft_utoa(data);
			ft_putstr_fd(data2, 1);
			free(data2);
			return (ft_unbrlen(data) + 1);
		}
		else if (arg->width > ft_unbrlen(data))
		{
			ret = ft_calloc(sizeof(char), (arg->width + 1));
			ft_memset(ret, ' ', arg->width);
			data2 = ft_utoa(data);
			len = ft_strlen(data2);
			ft_strlcpy(&ret[arg->width - len], data2, len + 1);
			ret[arg->width] = '\0';
			free(data2);
			ft_putstr_fd(ret, 1);
			free(ret);
			return (arg->width);
		}
		else
		{
			ft_putnbr_u_fd(data, 1);
			ret = ft_utoa(data);
			ret2 = ft_strlen(ret);
			free(ret);
		}
	}
	else
	{
		ft_putnbr_u_fd(data, 1);
		ret = ft_utoa(data);
		ret2 = ft_strlen(ret);
		free(ret);
	}
	return (ret2);
}
