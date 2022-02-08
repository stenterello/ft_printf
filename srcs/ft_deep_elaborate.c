/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deep_elaborate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 19:37:57 by ddelladi          #+#    #+#             */
/*   Updated: 2022/02/01 19:41:02 by ddelladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_deep_elaborate_aux(int *i, int orig)
{
	*i = orig;
	return (0);
}

int	ft_deep_elaborate(const char *s, int *i, va_list args)
{
	t_print	arg;
	int		orig;

	orig = *i;
	arg = ft_init_flags();
	if (ft_isflag(s[*i]))
		ft_take_flag(s[(*i)++], &arg);
	while (ft_isdigit(s[*i]) || ft_isflag(s[*i]))
	{
		if (ft_isdigit(s[*i]))
			ft_take_parameters(s, i, &arg);
		else
			ft_take_flag(s[*i], &arg);
		(*i)++;
	}
	if (ft_istype(s[*i]))
	{
		ft_take_type(s[*i], &arg);
		*i += 1;
	}
	else
		ft_deep_elaborate_aux(i, orig);
	return (synthesis(args, &arg));
}

int	ft_istype(char c)
{
	if (ft_strchr("cspdiuxX%", c))
		return (1);
	return (0);
}
