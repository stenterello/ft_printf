/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 19:39:10 by ddelladi          #+#    #+#             */
/*   Updated: 2022/02/01 19:39:11 by ddelladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr(long n, char *str, int *i)
{
	if (n > 9)
	{
		ft_putnbr(n / 10, str, i);
		ft_putnbr(n % 10, str, i);
	}
	else
		str[(*i)++] = n + '0';
}

int	ft_putnbr_u_fd(unsigned int n, int fd)
{
	int		count;
	char	*data;

	data = ft_utoa(n);
	count = ft_strlen(data);
	free(data);
	if (n > 9)
	{
		ft_putnbr_u_fd(n / 10, fd);
		ft_putnbr_u_fd(n % 10, fd);
	}
	else
		ft_putchar_fd(n + 48, fd);
	return (count);
}
