/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlers_d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 19:38:02 by ddelladi          #+#    #+#             */
/*   Updated: 2022/02/01 19:41:03 by ddelladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_prec_aux(char *str, int flag, t_print *arg)
{
	if (arg->prec && flag)
		ft_memset(&str[1], '0', arg->prec - 1);
	else if (arg->prec && !flag)
		ft_memset(str, '0', arg->prec);
}

void	ft_handle_minus(t_print *arg, char *text, int data, char *str)
{
	int	flag;
	int	num_len;
	int	dot_len;
	int	text_len;
	int	str_len;

	flag = ft_add_minus(arg, str, data);
	num_len = ft_int_nbrlen(data);
	dot_len = num_len - 1;
	text_len = ft_strlen(text);
	str_len = ft_strlen(str);
	ft_prec_aux(str, flag, arg);
	if (arg->width >= num_len && arg->prec < num_len)
		ft_memcpy(str, text, text_len);
	else if (arg->width >= num_len && arg->prec > dot_len && !flag)
		ft_memcpy(&str[arg->prec - text_len], text, text_len);
	else if (arg->width >= num_len && arg->prec > dot_len && flag)
		ft_memcpy(&str[arg->prec - text_len + 2], &text[1], text_len - 1);
	else if (arg->prec >= num_len && flag)
		ft_memcpy(&str[str_len - text_len + 1], &text[1], text_len);
	else if (arg->prec >= num_len)
		ft_memcpy(&str[str_len - text_len], text, text_len);
	str[str_len] = '\0';
}

void	ft_handle_width(t_print *arg, char *text, int data, char *str)
{
	int	flag;
	int	num_len;
	int	text_len;
	int	str_len;

	flag = ft_add_minus(arg, str, data);
	num_len = ft_int_nbrlen(data);
	text_len = ft_strlen(text);
	str_len = ft_strlen(str);
	if (arg->minus && arg->prec > ft_int_nbrlen(data) - 1 && flag)
		ft_memset(&str[1], '0', arg->prec);
	else if (arg->minus && arg->prec > ft_int_nbrlen(data) - 1 && !flag)
		ft_memset(str, '0', arg->prec);
	else if (arg->width >= num_len && arg->minus)
		ft_memcpy(str, text, text_len);
	else if (arg->width >= num_len && !flag)
		ft_memcpy(&str[str_len - text_len], text, text_len);
	else if (arg->width >= num_len && flag)
		ft_memcpy(&str[str_len - text_len + 1], &text[1], text_len - 1);
}

void	ft_handle_prec(t_print *arg, char *text, int data, char *str)
{
	int	flag;
	int	text_len;
	int	str_len;

	flag = ft_add_minus(arg, str, data);
	text_len = ft_strlen(text);
	str_len = ft_strlen(str);
	if (arg->prec >= text_len && !flag)
		ft_memcpy(&str[str_len - text_len], text, text_len);
	else if (arg->prec >= text_len && flag)
		ft_memcpy(&str[str_len - text_len + 1], &text[1], text_len);
}
