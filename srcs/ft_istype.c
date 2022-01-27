#include "../includes/ft_printf.h"

int	ft_istype(char c)
{
	if (ft_strchr("cspdiuxX%", c))
		return (1);
	return (0);
}
