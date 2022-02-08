/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 19:38:56 by ddelladi          #+#    #+#             */
/*   Updated: 2022/02/01 19:38:59 by ddelladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_puthex(int n, const char *base)
{
	int		len;
	char	*str;

	len = ft_strlen(ft_itoa(n));
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len] = 0;
	len -= 1;
	if (n == 0)
	{
		str[0] = 48;
		return (1);
	}
	while (n)
	{
		str[len] = base[n % 16];
		n /= 16;
		len--;
	}
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}
