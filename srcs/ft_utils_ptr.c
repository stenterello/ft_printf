/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 19:38:50 by ddelladi          #+#    #+#             */
/*   Updated: 2022/02/01 19:38:52 by ddelladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_if_add_zero_ptr(t_print *arg, char *str, size_t data)
{
	int	len;

	len = ft_ptrnbrlen(data, 16);
	if (arg->minus && arg->prec < arg->width && arg->prec > len)
		ft_memset(str, '0', arg->prec);
	else if (!arg->minus && arg->prec < arg->width
		&& arg->prec > len)
		ft_memset(&str[arg->width - arg->prec], '0', arg->prec);
	else if (arg->minus && arg->prec && arg->prec < arg->width)
		ft_memset(str, '0', arg->prec + 1);
}

int	ft_add_minus_ptr(t_print *arg, char *str, size_t data)
{
	if (arg->width > ft_ptrnbrlen(data, 16)
		&& arg->prec > ft_ptrnbrlen(data, 16)
		&& arg->prec && arg->width)
	{
		str[ft_strlen(str) - arg->prec - 1] = '-';
		return (1);
	}
	else if (!arg->minus && arg->width > ft_ptrnbrlen(data, 16)
		&& arg->prec && arg->width && arg->width > arg->prec)
	{
		str[ft_strlen(str) - ft_ptrnbrlen(data, 16)] = '-';
		return (1);
	}
	else if ((arg->dot || arg->zero))
	{
		str[0] = '-';
		return (1);
	}
	else if (arg->zero && arg->width > arg->prec)
	{
		str[arg->width - arg->prec - 1] = '-';
		return (1);
	}
	else
		return (0);
}

int	ft_no_flag_ptr(size_t data)
{
	int	count;

	ft_putstr_fd("0x", 1);
	count = ft_putnbr_base_ptr(data, "0123456789abcdef") + 2;
	return (count);
}

void	ft_add_zeroes_ptr(t_print *arg, char *ret, size_t data)
{
	if (arg->zero && arg->width > ft_int_nbrlen(data) && arg->minus)
		ft_memset(ret, '0', arg->width - ft_int_nbrlen(data));
	else if (arg->zero && arg->width > ft_int_nbrlen(data) && arg->minus)
		ft_memset(&ret[1], '0', arg->width - ft_int_nbrlen(data));
	else if (arg->zero && arg->width > ft_int_nbrlen(data))
		ft_memset(&ret[1], '0', arg->width - ft_int_nbrlen(data));
	else if (arg->zero && arg->width > ft_int_nbrlen(data))
		ft_memset(ret, '0', arg->width - ft_int_nbrlen(data));
}
