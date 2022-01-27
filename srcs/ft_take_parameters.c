#include "../includes/ft_printf.h"

void	ft_take_parameters(const char *s, int *i, t_print *arg)
{
	int		i2;
	int		orig;
	char	*param;

	i2 = 0;
	orig = *i;
	while (ft_isdigit(s[*i]))
	{
		(*i)++;
		i2++;
	}
	param = malloc(sizeof(char) * (i2 + 1));
	i2 = 0;
	*i = orig;
	while (ft_isdigit(s[*i]))
		param[i2++] = s[(*i)++];
	param[i2] = '\0';
	(*i)--;
	arg->flags = 1;
	arg->width = ft_atoi(param);
	free(param);
}
