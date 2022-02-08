/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlers_u.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 19:38:12 by ddelladi          #+#    #+#             */
/*   Updated: 2022/02/01 19:38:14 by ddelladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_handle_minus_u(t_print *arg, char *text, int data, char *str)
{
	int	num_len;
	int	dot_len;
	int	text_len;
	int	str_len;

	num_len = ft_unbrlen(data);
	dot_len = num_len - 1;
	text_len = ft_strlen(text);
	str_len = ft_strlen(str);
	if (arg->prec)
		ft_memset(str, '0', arg->prec);
	else if (arg->prec)
		ft_memset(str, '0', arg->prec);
	if (arg->width >= num_len && arg->prec < num_len)
		ft_memcpy(str, text, text_len);
	else if (arg->width >= num_len && arg->prec > dot_len)
		ft_memcpy(&str[arg->prec - text_len], text, text_len);
	else if (arg->width >= num_len && arg->prec > dot_len)
		ft_memcpy(&str[arg->prec - text_len], text, text_len);
	else if (arg->prec >= num_len)
		ft_memcpy(&str[str_len - text_len], text, text_len);
	else if (arg->prec >= num_len)
		ft_memcpy(&str[str_len - text_len], text, text_len);
	str[str_len] = '\0';
}

void	ft_handle_width_u(t_print *arg, char *text, int data, char *str)
{
	int	num_len;
	int	text_len;
	int	str_len;

	num_len = ft_int_nbrlen(data);
	text_len = ft_strlen(text);
	str_len = ft_strlen(str);
	if (arg->minus && arg->prec > ft_int_nbrlen(data) - 1)
		ft_memset(&str[1], '0', arg->prec);
	else if (arg->minus && arg->prec > ft_int_nbrlen(data) - 1)
		ft_memset(str, '0', arg->prec);
	else if (arg->width >= num_len && arg->minus)
		ft_memcpy(str, text, text_len);
	else if (arg->width >= num_len)
		ft_memcpy(&str[str_len - text_len], text, text_len);
	else if (arg->width >= num_len)
		ft_memcpy(&str[str_len - text_len + 1], &text[1], text_len - 1);
}

void	ft_handle_prec_u(t_print *arg, char *text, char *str)
{
	int	text_len;
	int	str_len;

	text_len = ft_strlen(text);
	str_len = ft_strlen(str);
	if (arg->prec >= text_len)
		ft_memcpy(&str[str_len - text_len], text, text_len);
	else if (arg->prec >= text_len)
		ft_memcpy(&str[str_len - text_len + 1], &text[1], text_len);
}
