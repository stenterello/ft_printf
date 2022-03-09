/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:36:13 by ddelladi          #+#    #+#             */
/*   Updated: 2022/02/04 17:36:18 by ddelladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_create_str_hex(t_print *arg, unsigned int data)
{
	char	*text;
	char	*ret;

	text = ft_utoa_hex(arg, data);
	if (arg->width > (int)ft_strlen(text) && arg->width > arg->prec)
	{
		ret = ft_calloc(arg->width + 1, sizeof(char));
		ft_memset(ret, ' ', arg->width);
		ret[arg->width] = '\0';
	}
	else if (arg->prec >= (int)ft_strlen(text) && arg->prec >= arg->width)
	{
		ret = ft_calloc(arg->prec + 1, sizeof(char));
		ft_memset(ret, '0', arg->prec);
		ret[arg->prec] = '\0';
	}
	else if (arg->hash)
	{
		ret = ft_calloc(ft_strlen(text) + 3, sizeof(char));
		ret[ft_strlen(text) + 2] = '\0';
	}
	else
		ret = ft_calloc(ft_strlen(text) + 1, sizeof(char));
	free(text);
	return (ret);
}

void	ft_add_data_hex(t_print *arg, char *ret, unsigned int data)
{
	char	*text;
	int		len;

	if (arg->dot && !arg->prec && data == 0 && !arg->width)
		return ;
	text = ft_utoa_hex(arg, data);
	len = ft_strlen(text);
	if (arg->zero && arg->width >= len && arg->prec < arg->width)
		ft_handle_zero_x(arg, text, ret);
	else if (arg->minus && arg->width >= len && !arg->dot)
		ft_handle_min_x(arg, text, ret);
	else if (arg->width >= len && arg->width > arg->prec)
		ft_handle_wid_x(arg, text, ret);
	else if (arg->prec >= len && arg->prec >= arg->width)
		ft_handle_prec_x(arg, text, ret);
	else if (arg->hash && data != 0)
		ft_handle_hash_x(arg, text, ret);
	else
		ft_strlcpy(ret, text, len + 1);
	ret[ft_strlen(ret)] = '\0';
	free(text);
}

int	ft_treat_x(va_list args, t_print *arg)
{
	unsigned int	data;
	char			*ret;
	int				count;

	data = va_arg(args, unsigned int);
	if (!arg->width && arg->dot && !arg->prec && data == 0)
		return (0);
	ret = ft_create_str_hex(arg, data);
	if (!ret)
		return (ft_no_flag_hex(arg, data));
	ft_if_add_zero_hex(arg, ret, data);
	ft_add_data_hex(arg, ret, data);
	if (!arg->dot)
		ft_add_zeroes_hex(arg, ret, data);
	ft_putstr_fd(ret, 1);
	count = ft_strlen(ret);
	free(ret);
	return (count);
}
