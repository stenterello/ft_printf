/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 19:39:45 by ddelladi          #+#    #+#             */
/*   Updated: 2022/02/01 19:39:52 by ddelladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_int_nbrlen(int n)
{
	int	i;

	i = 1;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	ft_dot_nbrlen(int n)
{
	int	i;

	i = 1;
	if (n == -2147483648)
		return (10);
	if (n < 0)
		n *= -1;
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

void	ft_add_data(t_print *arg, char *str, int data)
{
	char	*text;

	if (arg->dot && !arg->prec && data == 0)
		return ;
	if (data == -2147483648)
		text = "-2147483648";
	else
		text = ft_itoa(data);
	if (arg->minus && arg->width > arg->prec)
		ft_handle_minus(arg, text, data, str);
	else if (arg->width > arg->prec)
		ft_handle_width(arg, text, data, str);
	else if (arg->dot)
		ft_handle_prec(arg, text, data, str);
	else if ((arg->space || arg->plus) && data >= 0)
		ft_strlcpy(&str[1], text, ft_strlen(text) + 1);
	else
		ft_strlcpy(str, text, ft_strlen(text) + 1);
	str[ft_strlen(str)] = '\0';
	if (data != -2147483648)
		free(text);
}

int	ft_treat_d(va_list args, t_print *arg)
{
	int		data;
	char	*ret;
	int		count;

	data = va_arg(args, int);
	if (!arg->width && arg->dot && !arg->prec && data == 0)
		return (0);
	ret = ft_create_str(arg, data);
	if (!ret)
		return (ft_no_flag(data));
	ft_if_add_zero(arg, ret, data);
	ft_add_data(arg, ret, data);
	if (!arg->dot)
		ft_add_zeroes(arg, ret, data);
	ft_putstr_fd(ret, 1);
	count = ft_strlen(ret);
	free(ret);
	return (count);
}
