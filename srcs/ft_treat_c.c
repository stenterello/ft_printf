/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 19:39:39 by ddelladi          #+#    #+#             */
/*   Updated: 2022/02/01 19:39:42 by ddelladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_treated_start_c(va_list args, t_print *arg, char sep)
{
	char	*data;
	int		i;

	i = 0;
	data = ft_calloc(arg->width + 1, sizeof(char));
	ft_memset(data, sep, arg->width);
	data[0] = (char)va_arg(args, int);
	data[arg->width] = '\0';
	while (i < arg->width)
		ft_putchar_fd(data[i++], 1);
	free(data);
	return (arg->width);
}

int	ft_treated_end_c(va_list args, t_print *arg, char sep)
{
	char	*data;

	data = ft_calloc(arg->width + 1, sizeof(char));
	ft_memset(data, sep, arg->width);
	data[arg->width - 1] = (char)va_arg(args, int);
	data[arg->width] = '\0';
	ft_putstr_fd(data, 1);
	if (data[arg->width - 1] == '\0')
		ft_putchar_fd('\0', 1);
	free(data);
	return (arg->width);
}

int	ft_treat_c(va_list args, t_print *arg)
{
	char	c;

	if (arg->width && arg->flags)
	{
		if (arg->minus)
			ft_treated_start_c(args, arg, ' ');
		else if (arg->zero)
			ft_treated_end_c(args, arg, '0');
		else if (arg->hash || arg->space)
			ft_treated_end_c(args, arg, ' ');
		else if (arg->width)
			ft_treated_end_c(args, arg, ' ');
		return (arg->width);
	}
	else
	{
		c = (char)va_arg(args, int);
		ft_putchar_fd(c, 1);
	}
	return (1);
}
