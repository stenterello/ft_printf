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

int	ft_dot_nbrlen(int n)
{
	int	i;

	i = 1;
	if (n == -2147483648)
		return (10);
	if (n < 0)
		n *= -1;
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	ft_print_d_start(t_print *arg, int data, char c, int measure)
{
	char	*ret;
	char	*data2;

	data2 = ft_itoa(data);
	ret = NULL;
	if (arg->width && !arg->prec)
	{
		ret = ft_calloc(measure, sizeof(char));
		ft_memset(ret, c, measure);
		if (data != 0)
			ft_strlcpy(ret, data2, ft_strlen(data2) + 1);
		else if (data == 0 && arg->width && !arg->dot)
			ft_strlcpy(ret, data2, ft_strlen(data2) + 1);
		if (arg->width > (int)ft_strlen(data2))
			ret[ft_strlen(data2)] = c;
	}
	else
	{
		if (data < 0 && measure == arg->prec)
		{
			ret = ft_calloc(measure + 1, sizeof(char));
			ft_memset(ret, c, measure + 1);
			ft_memset(ret, 48, arg->prec + 1);
		}
		else
		{
			ret = ft_calloc(measure, sizeof(char));
			ft_memset(ret, c, measure);
			ft_memset(ret, 48, arg->prec);
		}
		if (arg->prec > ft_dot_nbrlen(data) && data >= 0)
		{
			ft_strlcpy(&ret[arg->prec - ft_strlen(data2)], data2, ft_strlen(data2) + 1);
			ret[arg->prec] = c;
		}
		else if (arg->prec > ft_dot_nbrlen(data) && data < 0)
		{
			ft_strlcpy(&ret[arg->prec - ft_dot_nbrlen(data) + 1], &data2[1], ft_dot_nbrlen(data) + 1);
			ret[arg->prec + 1] = c;
			ret[0] = '-';
		}
		else
		{
			ft_strlcpy(ret, data2, ft_strlen(data2) + 1);
			if ((int)ft_strlen(data2) != measure)
				ret[ft_strlen(data2)] = c;
		}
	}
	ft_putstr_fd(ret, 1);
	data = ft_strlen(ret);
	free(ret);
	free(data2);
	return (data);
}

int	ft_print_d_end(t_print *arg, int data, char c, int measure)
{
	char	*ret;
	char	*data2;

	data2 = ft_itoa(data);
	if (data < 0 && arg->prec && !arg->zero)
	{
		ret = ft_calloc(measure + 1, sizeof(char));
		ft_memset(ret, c, measure + 1);
		ft_strlcpy(&ret[measure - ft_dot_nbrlen(data) + 1], &data2[1], ft_int_nbrlen(data) + 1);
	}
	else if (data < 0 && arg->zero && arg->width > (int)ft_strlen(data2))
	{
		ret = ft_calloc(measure + 1, sizeof(char));
		ft_memset(ret, c, measure);
		ft_strlcpy(&ret[measure - ft_dot_nbrlen(data)], &data2[1], ft_int_nbrlen(data) + 1);
	}
	else if (data < 0 && arg->zero && arg->width < (int)ft_strlen(data2))
	{
		ret = ft_calloc(ft_strlen(data2), sizeof(char));
		ft_strlcpy(ret, data2, ft_strlen(data2) + 1);
	}
	else if (arg->dot && !arg->prec && data == 0)
	{
		ret = ft_calloc(measure, sizeof(char));
		ft_memset(ret, 32, measure);
	}
	else if (arg->zero && arg->width < (int)ft_strlen(data2))
	{
		ret = ft_calloc(ft_strlen(data2), sizeof(char));
		ft_strlcpy(ret, data2, ft_strlen(data2) + 1);
	}
	else
	{
		ret = ft_calloc(measure, sizeof(char));
		ft_memset(ret, c, measure);
		if (data != 0)
			ft_strlcpy(&ret[measure - ft_int_nbrlen(data)], data2, ft_int_nbrlen(data) + 1);
	}
	if ((arg->prec || arg->zero) && data < 0 && measure >= ft_dot_nbrlen(data))
	{
		ret[0] = '-';
		ret[measure + 1] = '\0';
	}
	else if (arg->prec && arg->prec < arg->width)
	{
		ft_memset(&ret[measure - arg->prec], 48, arg->prec);
		ft_strlcpy(&ret[arg->width - ft_strlen(data2)], data2, ft_strlen(data2) + 1);
		ret[arg->prec] = c;
	}
	else if (measure > (int)ft_strlen(data2))
		ret[measure] = '\0';
	ft_putstr_fd(ret, 1);
	data = ft_strlen(ret);
	free(ret);
	free(data2);
	return (data);
}

int	ft_treat_d(va_list args, t_print *arg)
{
	int		data;
	int		len;

	data = (int)va_arg(args, int);
	len = 0;
	if (arg->dot && arg->prec >= arg->width && arg->prec >= ft_dot_nbrlen(data))
		data = ft_print_d_end(arg, data, 48, arg->prec);
	else if (arg->dot && !arg->prec && data == 0 && !arg->width)
		return (0);
	else if (arg->minus && arg->width && arg->width > arg->prec)
		data = ft_print_d_start(arg, data, 32, arg->width);
	else if (arg->minus && arg->width && arg->prec > arg->width && arg->prec > ft_dot_nbrlen(data))
		data = ft_print_d_start(arg, data, 32, arg->prec);
	else if (arg->minus && arg->width && !arg->dot)
		data = ft_print_d_start(arg, data, 32, arg->width);
	else if (arg->width > ft_int_nbrlen(data) && !arg->dot && !arg->zero)
		data = ft_print_d_end(arg, data, 32, arg->width);
	else if (arg->prec > ft_dot_nbrlen(data) && !arg->width)
		data = ft_print_d_end(arg, data, 48, arg->prec);
	else if (arg->zero && !arg->dot)
		data = ft_print_d_end(arg, data, 48, arg->width);
	else if (arg->zero)
		data = ft_print_d_end(arg, data, 32, arg->width);
	else
	{
		ft_putnbr_fd(data, 1);
		return (ft_int_nbrlen(data));
	}
	return (data);
}
