/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deep_elaborate_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:25:22 by ddelladi          #+#    #+#             */
/*   Updated: 2022/02/04 17:25:23 by ddelladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	ft_isflag(const char c)
{
	if (ft_strchr("-0.# +", c))
		return (1);
	return (0);
}

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
	if (!arg->dot)
		arg->width = ft_atoi(param);
	else
		arg->prec = ft_atoi(param);
	free(param);
}

void	ft_take_type(const char c, t_print *arg)
{
	arg->type = c;
}
