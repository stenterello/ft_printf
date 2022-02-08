/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 19:40:33 by ddelladi          #+#    #+#             */
/*   Updated: 2022/02/01 19:40:34 by ddelladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_create_str_u(t_print *arg, unsigned int data)
{
	char	*ret;

	if (arg->width > arg->prec && arg->width >= ft_unbrlen(data))
	{
		ret = ft_calloc(arg->width + 1, sizeof(char));
		ft_memset(ret, ' ', arg->width);
		ret[arg->width] = '\0';
	}
	else if (arg->prec >= arg->width
		&& arg->prec > ft_unbrlen(data))
	{
		ret = ft_calloc(arg->prec + 1, sizeof(char));
		ft_memset(ret, '0', arg->prec);
		ret[arg->prec] = '\0';
	}
	else
		return (NULL);
	return (ret);
}

void	ft_if_add_zero_u(t_print *arg, char *str, unsigned int data)
{
	if (arg->minus && arg->prec < arg->width && arg->prec > ft_unbrlen(data))
		ft_memset(str, '0', arg->prec);
	else if (!arg->minus && arg->prec < arg->width
		&& arg->prec > ft_unbrlen(data))
		ft_memset(&str[arg->width - arg->prec], '0', arg->prec);
	else if (arg->minus && arg->prec && arg->prec < arg->width)
		ft_memset(str, '0', arg->prec + 1);
}

int	ft_add_minus_u(t_print *arg, char *str, unsigned int data)
{
	if (arg->width > ft_unbrlen(data) && arg->prec > ft_unbrlen(data)
		&& arg->prec && arg->width)
	{
		str[ft_strlen(str) - arg->prec - 1] = '-';
		return (1);
	}
	else if (!arg->minus && arg->width > ft_unbrlen(data)
		&& arg->prec && arg->width && arg->width > arg->prec)
	{
		str[ft_strlen(str) - ft_unbrlen(data)] = '-';
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

int	ft_no_flag_u(unsigned int data)
{
	ft_putnbr_u_fd(data, 1);
	return (ft_unbrlen(data));
}

void	ft_add_zeroes_u(t_print *arg, char *ret, unsigned int data)
{
	if (arg->zero && arg->width > ft_unbrlen(data) && arg->minus)
		ft_memset(ret, '0', arg->width - ft_unbrlen(data));
	else if (arg->zero && arg->width > ft_unbrlen(data) && arg->minus)
		ft_memset(ret, '0', arg->width - ft_unbrlen(data));
	else if (arg->zero && arg->width > ft_unbrlen(data))
		ft_memset(ret, '0', arg->width - ft_unbrlen(data));
	else if (arg->zero && arg->width > ft_unbrlen(data))
		ft_memset(ret, '0', arg->width - ft_unbrlen(data));
}
