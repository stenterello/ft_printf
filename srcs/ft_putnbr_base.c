/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 19:39:02 by ddelladi          #+#    #+#             */
/*   Updated: 2022/02/01 19:39:04 by ddelladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putnbr_base(int nbr, char *base)
{
	long	i;

	i = 0;
	if (nbr / (int)(ft_strlen(base)) > 0)
	{
		i += ft_putnbr_base((nbr / (int)(ft_strlen(base))), base);
		i += ft_putnbr_base((nbr % (int)(ft_strlen(base))), base);
	}
	else
	{
		ft_putchar_fd(base[nbr % (ft_strlen(base))], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr_base_ptr(size_t nbr, char *base)
{
	int	i;

	i = 2;
	if (nbr / ft_strlen(base) > 0)
	{
		i += ft_putnbr_base_ptr((nbr / ft_strlen(base)), base);
		i += ft_putnbr_base_ptr((nbr % ft_strlen(base)), base);
	}
	else
	{
		ft_putchar_fd(base[nbr % (ft_strlen(base))], 1);
		i++;
	}
	return (i);
}
