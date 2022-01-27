#include "../includes/ft_printf.h"

t_print	ft_init_flags(void)
{
	t_print	elem;

	elem.flags = 0;
	elem.width = 0;
	elem.space = 0;
	elem.dot = 0;
	elem.plus = 0;
	elem.minus = 0;
	elem.hash = 0;
	elem.percent = 0;
	elem.zero = 0;
	elem.prec = 0;
	elem.type = 0;
	return (elem);
}
