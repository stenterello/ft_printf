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

int	ft_treated_d_start(t_print *arg, int data, int c)
{
	char	*ret;
	char	*data2;

	ret = ft_calloc(sizeof(char), (arg->width + 2));
	ft_memset(ret, c, arg->width);
	data2 = ft_itoa(data);
	ft_strlcpy(ret, data2, ft_strlen(data2) + 1);
	ret[ft_strlen(data2)] = c;
	ret[arg->width] = '\0';
	free(data2);
	ft_putstr_fd(ret, 1);
	free(ret);
	return (arg->width);
}

int	ft_treated_d_end(t_print *arg, int data, int c)
{
	char	*ret;
	char	*data2;
	int		l;

	ret = ft_calloc(sizeof(char), (arg->width + 3));
	ft_memset(ret, c, arg->width + 1);
	data2 = ft_itoa(data);
	l = ft_strlen(data2);
	if (data > 0 && arg->plus)
		ret[arg->width - l - 1] = '+';
	else if (data < 0 && (arg->zero || arg->dot))
	{
		ft_strlcpy(&ret[arg->width - l + 2], &data2[1], l);
		ret[0] = '-';
		ret[arg->width + 1] = '\0';
	}
	else
	{
		ft_strlcpy(&ret[arg->width - l], data2, l + 1);
		ret[arg->width] = '\0';
	}	
	free(data2);
	ft_putstr_fd(ret, 1);
	l = ft_strlen(ret);
	free(ret);
	return (l);
}

int	ft_treat_d(va_list args, t_print *arg)
{
	int		data;
	char	*ret;
	char	*data2;
	int		len;

	data = (int)va_arg(args, int);
	len = 0;
	if (arg->minus && arg->width > ft_int_nbrlen(data))
		data = ft_treated_d_start(arg, data, ' ');
	else if ((arg->zero || arg->dot) && arg->width > ft_dot_nbrlen(data))
		data = ft_treated_d_end(arg, data, '0');
	else if ((arg->hash || arg->space) && arg->width > ft_int_nbrlen(data))
		data = ft_treated_d_end(arg, data, ' ');
	//else if (arg->dot)
	//{
	//	if (data < 0)
	//	{
	//		ft_putchar_fd('-', 1);
	//		data *= -1;
	//		len += 1;
	//		ret = ft_itoa(data);
	//		while (len < arg->width - (int)ft_strlen(ret) + 1)
	//		{
	//			ft_putchar_fd('0', 1);
	//			len += 1;
	//		}
	//	}
	//	else
	//	{
	//		ret = ft_itoa(data);
	//		while (len < arg->width - (int)ft_strlen(ret))
	//		{
	//			ft_putchar_fd('0', 1);
	//			len += 1;
	//		}
	//	}
	//	ft_putstr_fd(ret, 1);
	//	len += ft_strlen(ret);
	//	free(ret);
	//	return (len);
	//}
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
		ft_treated_d_end(arg, data, ' ');
	else if (arg->width > ft_int_nbrlen(data))
		ft_treated_d_end(arg, data, ' ');
	else
	{
		ft_putnbr_fd(data, 1);
		ret = ft_itoa(data);
		data = ft_strlen(ret);
		free(ret);
	}
	return (data);
}
