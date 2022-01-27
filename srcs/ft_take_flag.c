#include "../includes/ft_printf.h"

void	ft_take_flag(const char c, t_print *arg)
{
	arg->flags = 1;
	if (c == '-')
		arg->minus = 1;
	if (c == '0')
		arg->zero = 1;
	if (c == '.')
		arg->dot = 1;
	if (c == '#')
		arg->hash = 1;
	if (c == ' ')
		arg->space = 1;
	if (c == '+')
		arg->plus = 1;
}
