/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 19:40:19 by ddelladi          #+#    #+#             */
/*   Updated: 2022/02/01 19:40:20 by ddelladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_add_data_u(t_print *arg, char *str, unsigned int data)
{
	char	*text;

	if (arg->dot && !arg->prec && data == 0)
		return ;
	text = ft_utoa(data);
	if (arg->minus)
		ft_handle_minus_u(arg, text, data, str);
	else if (arg->width > arg->prec)
		ft_handle_width_u(arg, text, data, str);
	else if (arg->dot)
		ft_handle_prec_u(arg, text, str);
	free(text);
}

int	ft_treat_u(va_list args, t_print *arg)
{
	unsigned int	data;
	char			*ret;
	int				count;

	data = (unsigned int)va_arg(args, unsigned int);
	if (arg->flags)
	{	
		if (!arg->width && arg->dot && !arg->prec && data == 0)
			return (0);
		ret = ft_create_str_u(arg, data);
		if (!ret)
			return (ft_no_flag_u(data));
		ft_if_add_zero_u(arg, ret, data);
		ft_add_data_u(arg, ret, data);
		if (!arg->dot)
			ft_add_zeroes_u(arg, ret, data);
		ft_putstr_fd(ret, 1);
		count = ft_strlen(ret);
		free(ret);
		return (count);
	}
	else
		ft_putnbr_u_fd(data, 1);
	return (ft_unbrlen(data));
}
