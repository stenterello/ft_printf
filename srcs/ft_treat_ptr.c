#include "../includes/ft_printf.h"

int	ft_ptrnbrlen(size_t n)
{
	int	i;

	i = 1;
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	if (i > 10)
		return (14);
	return (i);
}

int	ft_fill_write_end_ptr(size_t data, char c, t_print *arg)
{
	char	*data2;
	int		len;

	data2 = ft_calloc(sizeof(char), arg->width + 1);
	ft_memset(data2, c, arg->width + 1);
	data2[arg->width - (ft_ptrnbrlen(data))] = '\0';
	ft_putstr_fd(data2, 1);
	len = ft_strlen(data2);
	ft_putstr_fd("0x", 1);
	len += ft_putnbr_base_ptr(data, "0123456789abcdef") + 2;
	free(data2);
	return (len);
}

int	ft_fill_write_start_ptr(size_t data, char c, t_print *arg)
{
	int	len;

	len = 2;
	ft_putstr_fd("0x", 1);
	len += ft_putnbr_base_ptr(data, "0123456789abcdef");
	while (len < arg->width)
	{
		ft_putchar_fd(c, 1);
		len++;
	}
	return (len);
}


int	ft_treat_ptr(va_list args, t_print *arg)
{
	size_t	data;
	char	*base;
	int		count;
	char	*convert;

	base = "0123456789abcdef";
	data = va_arg(args, size_t);
	count = 0;
	convert = ft_get_hex(data, base);
	if (arg->minus && arg->width > ft_ptrnbrlen(data))
		count += ft_fill_write_start_ptr(data, ' ', arg);
	else if (arg->width > ft_ptrnbrlen(data))
		count += ft_fill_write_end_ptr(data, ' ', arg);
	else
	{
		ft_putstr_fd("0x", 1);
		count += 2;
		count += ft_putnbr_base_ptr(data, base);
	}
	free(convert);
	return (count);
}
