/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_d_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:38:30 by ddelladi          #+#    #+#             */
/*   Updated: 2022/02/04 17:38:31 by ddelladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_calloc_string_d(t_print *arg, int size, int data, char c)
{
	char	*ret;

	if ((arg->space || arg->plus) && data >= 0)
		++size;
	ret = ft_calloc(size + 1, sizeof(char));
	ft_memset(ret, c, size);
	if (arg->space && data >= 0)
		ret[0] = ' ';
	else if (arg->plus && data >= 0)
		ret[0] = '+';
	ret[size] = '\0';
	return (ret);
}

char	*ft_create_str(t_print *arg, int data)
{
	char	*ret;

	if (arg->width > arg->prec && arg->width >= ft_int_nbrlen(data))
		ret = ft_calloc_string_d(arg, arg->width, data, ' ');
	else if (arg->prec >= arg->width
		&& arg->prec > ft_dot_nbrlen(data) && data < 0)
		ret = ft_calloc_string_d(arg, arg->prec + 1, data, '0');
	else if (arg->prec >= arg->width && arg->prec > ft_dot_nbrlen(data))
		ret = ft_calloc_string_d(arg, arg->prec, data, '0');
	else if ((arg->space || arg->plus) && data >= 0)
		ret = ft_calloc_string_d(arg, ft_int_nbrlen(data), data, ' ');
	else
		return (NULL);
	return (ret);
}
