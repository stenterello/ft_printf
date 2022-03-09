/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlers_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:26:09 by ddelladi          #+#    #+#             */
/*   Updated: 2022/02/04 17:26:10 by ddelladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_handle_min_x(t_print *arg, char *text, char *ret)
{
	if (arg->width >= (int)ft_strlen(text) && !arg->dot)
		ft_set_string3(ret, text, ' ', arg->width);
	return ;
}

void	ft_handle_wid_x(t_print *arg, char *text, char *ret)
{
	int	len;

	len = ft_strlen(text);
	if (arg->dot && !arg->prec && !ft_strncmp(text, "0", 1))
		ft_memset(ret, ' ', arg->width);
	else if (!arg->minus && arg->width >= len)
		ft_set_string(ret, text, ' ', arg->width);
	else if (arg->minus && arg->width >= len && arg->prec > len)
		ft_set_string2(ret, text, arg);
	else if (arg->minus && arg->width >= len)
	{
		ft_memcpy(ret, text, ft_strlen(text));
		ft_memset(&ret[ft_strlen(text)], ' ', arg->width - ft_strlen(text));
	}
	return ;
}

void	ft_handle_prec_x(t_print *arg, char *text, char *ret)
{
	int	len;

	len = ft_strlen(text);
	if (!arg->minus && arg->prec >= len && arg->prec >= arg->width)
	{
		ft_memset(ret, '0', arg->prec - ft_strlen(text));
		ft_memcpy(&ret[arg->prec - ft_strlen(text)], text, ft_strlen(text));
	}
	else if (arg->minus && arg->width > arg->prec && arg->width >= len)
		ft_set_string2(ret, text, arg);
	else if (arg->minus && arg->prec >= arg->width && arg->prec >= len)
	{
		ft_memset(ret, '0', arg->prec - ft_strlen(text));
		ft_memcpy(&ret[arg->prec - ft_strlen(text)], text, ft_strlen(text));
	}
	return ;
}

void	ft_handle_hash_x(t_print *arg, char *text, char *ret)
{
	ret[0] = '0';
	if (arg->type == 'x')
		ret[1] = 'x';
	else
		ret[1] = 'X';
	ft_memcpy(&ret[2], text, ft_strlen(text));
}

void	ft_handle_zero_x(t_print *arg, char *text, char *ret)
{
	int	len;

	len = ft_strlen(text);
	if (arg->dot && !arg->prec && !ft_strncmp(text, "0", 1))
		ft_memset(ret, ' ', arg->width);
	else if (arg->prec < arg->width && arg->prec > len)
	{
		ft_memset(&ret[arg->width - arg->prec], '0', arg->prec - len);
		ft_memcpy(&ret[arg->width - len], text, len);
	}
	else if (arg->prec && arg->prec < arg->width)
		ft_memcpy(&ret[arg->width - len], text, len);
	else
	{
		ft_memset(ret, '0', arg->width - len);
		ft_memcpy(&ret[arg->width - len], text, len);
	}
}
