#include "../includes/ft_printf.h"

int	ft_isflag(const char c)
{
	if (ft_strchr("-0.# +", c))
		return (1);
	return (0);
}
