#include "../includes/ft_printf.h"

int	ft_fill_write_end_free(t_print *arg, char *str, char c)
{
	char	*data;
	int		len;

	len = ft_strlen(str);
	data = ft_calloc(sizeof(char), (arg->width + 1));
	ft_memset(data, c, arg->width);
	if (str[0] != '\0')
		ft_strlcpy(&data[arg->width - len], str, len + 1);
	data[arg->width] = '\0';
	ft_putstr_fd(data, 1);
	len = ft_strlen(data);
	free(data);
	return (len);
}

int	ft_fill_write_start_free(t_print *arg, char *str, char c)
{
	char	*data;
	int		len;

	len = ft_strlen(str);
	data = ft_calloc(sizeof(char), (arg->width + 1));
	ft_memset(data, c, arg->width);
	if (str[0] != '\0')
	{
		ft_strlcpy(data, str, len + 1);
		data[len] = c;
	}
	ft_putstr_fd(data, 1);
	len = ft_strlen(data);
	free(data);
	return (len);
}

int	ft_treat_s(va_list args, t_print *arg)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)va_arg(args, char *);
	if (!str)
		str = "(null)";
	if (arg->zero)
		i += ft_fill_write_end_free(arg, str, 48);
	else if (arg->dot)
	{
		while (i < arg->width && str[i] != '\0')
		{
			ft_putchar_fd(str[i], 1);
			i++;
		}
	}
	else if (arg->space && arg->width > (int)ft_strlen(str))
		i += ft_fill_write_end_free(arg, str, 32);
	else if (arg->minus && arg->width > (int)ft_strlen(str))
		i += ft_fill_write_start_free(arg, str, 32);
	else if (arg->width > (int)ft_strlen(str))
		i += ft_fill_write_end_free(arg, str, 32);
	else
	{
		i = ft_strlen(str);
		ft_putstr_fd(str, 1);
	}
	return (i);
}
