/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   synthesis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 19:40:45 by ddelladi          #+#    #+#             */
/*   Updated: 2022/02/01 19:40:51 by ddelladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	synthesis(va_list args, t_print *arg)
{
	int	counter;

	counter = 0;
	if (arg->type == 'c')
		counter += ft_treat_c(args, arg);
	if (arg->type == 's')
		counter += ft_treat_s(args, arg);
	if (arg->type == 'p')
		counter += ft_treat_ptr(args, arg);
	if (arg->type == 'd' || arg->type == 'i')
		counter += ft_treat_d(args, arg);
	if (arg->type == 'u')
		counter += ft_treat_u(args, arg);
	if (arg->type == 'x' || arg->type == 'X')
		counter += ft_treat_x(args, arg);
	if (arg->type == '%')
		counter += ft_treat_percent(arg);
	return (counter);
}
