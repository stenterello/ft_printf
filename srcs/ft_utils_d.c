/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 19:37:49 by ddelladi          #+#    #+#             */
/*   Updated: 2022/02/01 19:41:01 by ddelladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_if_add_zero(t_print *arg, char *str, int data)
{
	if (arg->minus && arg->prec < arg->width && arg->prec > ft_int_nbrlen(data))
		ft_memset(str, '0', arg->prec);
	else if (!arg->minus && arg->prec < arg->width
		&& arg->prec > ft_int_nbrlen(data))
		ft_memset(&str[arg->width - arg->prec], '0', arg->prec);
	else if (arg->minus && arg->prec && arg->prec < arg->width)
		ft_memset(str, '0', arg->prec + 1);
}

int	ft_add_minus(t_print *arg, char *str, int data)
{
	if (arg->width > ft_int_nbrlen(data) && arg->prec > ft_int_nbrlen(data)
		&& arg->prec && arg->width && data < 0)
	{
		str[ft_strlen(str) - arg->prec - 1] = '-';
		return (1);
	}
	else if (!arg->minus && arg->width > ft_int_nbrlen(data)
		&& arg->prec && arg->width && data < 0 && arg->width > arg->prec)
	{
		str[ft_strlen(str) - ft_int_nbrlen(data)] = '-';
		return (1);
	}
	else if (data < 0 && (arg->dot || arg->zero))
	{
		str[0] = '-';
		return (1);
	}
	else if (data < 0 && arg->zero && arg->width > arg->prec)
	{
		str[arg->width - arg->prec - 1] = '-';
		return (1);
	}
	else
		return (0);
}

int	ft_no_flag(int data)
{
	ft_putnbr_fd(data, 1);
	return (ft_int_nbrlen(data));
}

void	ft_add_zeroes(t_print *arg, char *ret, int data)
{
	if (arg->zero && arg->width > ft_int_nbrlen(data) && data > 0 && arg->minus)
		ft_memset(ret, '0', arg->width - ft_int_nbrlen(data));
	else if (arg->zero && arg->width > ft_int_nbrlen(data) && arg->minus)
		ft_memset(&ret[1], '0', arg->width - ft_int_nbrlen(data));
	else if (arg->zero && arg->width > ft_int_nbrlen(data) && data < 0)
		ft_memset(&ret[1], '0', arg->width - ft_int_nbrlen(data));
	else if (arg->zero && arg->width > ft_int_nbrlen(data))
		ft_memset(ret, '0', arg->width - ft_int_nbrlen(data));
}
