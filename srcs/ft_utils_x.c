/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:40:14 by ddelladi          #+#    #+#             */
/*   Updated: 2022/02/04 17:40:15 by ddelladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_utoa_hex(t_print *arg, unsigned int data)
{
	char	*ret;
	char	*base;
	int		len;

	if (arg->type == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	len = ft_hexnbrlen(data);
	ret = ft_calloc(len + 1, sizeof(char));
	if (!ret)
		return (0);
	ret[len--] = '\0';
	while (len >= 0)
	{
		ret[len] = base[data % 16];
		data = data / 16;
		len--;
	}
	return (ret);
}

int	ft_no_flag_hex(t_print *arg, unsigned int data)
{
	char	*text;
	int		len;

	text = ft_utoa_hex(arg, data);
	ft_putstr_fd(text, 1);
	len = ft_strlen(text);
	free(text);
	return (len);
}

void	ft_if_add_zero_hex(t_print *arg, char *str, int data)
{
	if (arg->minus && arg->prec < arg->width && arg->prec > ft_hexnbrlen(data))
		ft_memset(str, '0', arg->prec);
	else if (!arg->minus && arg->prec < arg->width
		&& arg->prec > ft_hexnbrlen(data))
		ft_memset(&str[arg->width - arg->prec], '0', arg->prec);
	else if (arg->minus && arg->prec && arg->prec < arg->width)
		ft_memset(str, '0', arg->prec + 1);
}

int	ft_hexnbrlen(unsigned int data)
{
	int	i;

	if (data == 0)
		return (1);
	i = 0;
	while (data > 0)
	{
		data = data / 16;
		i++;
	}
	return (i);
}

void	ft_add_zeroes_hex(t_print *arg, char *ret, unsigned int data)
{
	if (arg->zero && arg->width > ft_hexnbrlen(data))
		ft_memset(ret, '0', arg->width - ft_hexnbrlen(data));
}
