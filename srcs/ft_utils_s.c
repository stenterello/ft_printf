/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 19:39:14 by ddelladi          #+#    #+#             */
/*   Updated: 2022/02/01 19:39:16 by ddelladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

char	*ft_create_str_s(t_print *arg, char *data)
{
	char	*ret;

	if (arg->prec > (int)ft_strlen(data) && arg->width > (int)ft_strlen(data))
	{
		ret = ft_calloc(arg->width + 1, sizeof(char));
		ft_memset(ret, ' ', arg->width);
		ret[arg->width] = '\0';
	}
	else if (arg->width > arg->prec && arg->width >= (int)ft_strlen(data))
	{
		ret = ft_calloc(arg->width + 1, sizeof(char));
		ft_memset(ret, ' ', arg->width);
		ret[arg->width] = '\0';
	}
	else if (arg->prec >= arg->width && arg->prec)
	{
		ret = ft_calloc(arg->prec + 1, sizeof(char));
		ft_memset(ret, ' ', arg->prec);
		ret[arg->prec] = '\0';
	}
	else
		return (NULL);
	return (ret);
}

int	ft_no_flag_s(t_print *arg, char *data)
{
	if (arg->dot && !arg->prec)
		return (0);
	ft_putstr_fd(data, 1);
	return (ft_strlen(data));
}
