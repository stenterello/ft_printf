#include "../includes/ft_printf.h"

int	ft_deep_elaborate(const char *s, int *i, va_list args)
{
	t_print	arg;
	int		orig;
	int		counter;

	counter = 0;
	orig = *i;
	arg = ft_init_flags();
	if (ft_isflag(s[*i]))
		ft_take_flag(s[(*i)++], &arg);
	while (ft_isdigit(s[*i]) || ft_isflag(s[*i]))
	{
		if (ft_isdigit(s[*i]))
			ft_take_parameters(s, i, &arg);
		else
			ft_take_flag(s[(*i)], &arg);
		(*i)++;
	}
	if (ft_istype(s[*i]))
	{
		ft_take_type(s[*i], &arg);
		*i += 1;
	}
	else
	{
		*i = orig;
		return (0);
	}
	counter += synthesis(args, &arg);
	return (counter);
}
