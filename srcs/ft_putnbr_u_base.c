/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 19:39:05 by ddelladi          #+#    #+#             */
/*   Updated: 2022/02/01 19:39:06 by ddelladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putnbr_u_base(unsigned long long nbr, char *base)
{
	long	i;

	i = 0;
	if (nbr / (int)(ft_strlen(base)) > 0)
	{
		i += ft_putnbr_base((nbr / (ft_strlen(base))), base);
		i += ft_putnbr_base((nbr % (ft_strlen(base))), base);
	}
	else
	{
		ft_putchar_fd(base[nbr % (ft_strlen(base))], 1);
		i++;
	}
	return (i);
}

int	ft_u_base_len(unsigned long long nbr, char *base)
{
	long	i;

	i = 0;
	if (nbr / (int)(ft_strlen(base)) > 0)
	{
		i += ft_u_base_len((nbr / (ft_strlen(base))), base);
		i += ft_u_base_len((nbr % (ft_strlen(base))), base);
	}
	else
		i++;
	return (i);
}
