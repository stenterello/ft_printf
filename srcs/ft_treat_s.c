/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 19:40:13 by ddelladi          #+#    #+#             */
/*   Updated: 2022/02/01 19:40:15 by ddelladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_add_data_s(t_print *arg, char *str, char *data)
{
	int	len;

	len = ft_strlen(data);
	if (arg->minus && arg->prec < (int)ft_strlen(data) && arg->prec)
		ft_memcpy(str, data, arg->prec);
	else if (arg->minus)
		ft_memcpy(str, data, len);
	else if (arg->width > arg->prec)
		ft_memcpy(&str[ft_strlen(str) - len], data, len);
	else if (arg->dot && !arg->prec)
		str[0] = '\0';
	else if (arg->dot)
		ft_memcpy(str, data, arg->prec);
	str[ft_strlen(str)] = '\0';
}

int	ft_treat_s(va_list args, t_print *arg)
{
	char	*data;
	char	*ret;
	int		count;

	data = va_arg(args, char *);
	if (!data)
		data = "(null)";
	ret = ft_create_str_s(arg, data);
	if (!ret)
		return (ft_no_flag_s(arg, data));
	ft_add_data_s(arg, ret, data);
	ft_putstr_fd(ret, 1);
	count = ft_strlen(ret);
	free(ret);
	return (count);
}
