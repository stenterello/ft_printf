#include "../includes/ft_printf.h"

int	synthesis(va_list args, t_print *arg)
{
	int	counter;

	counter = 0;
	if (arg->type == 'c')
		counter += ft_treat_c(args, arg);
	if (arg->type == 's')
		counter += ft_treat_s(args, arg);
	if (arg->type == 'p')
		counter += ft_treat_ptr(args, arg);
	if (arg->type == 'd' || arg->type == 'i')
		counter += ft_treat_d(args, arg);
	if (arg->type == 'u')
		counter += ft_treat_u(args, arg);
	if (arg->type == 'x')
		counter += ft_treat_hex(args);
	if (arg->type == 'X')
		counter += ft_treat_HEX(args);
	if (arg->type == '%')
		counter += ft_treat_percent();
	return (counter);
}
