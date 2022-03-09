/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_ptr_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:31:01 by ddelladi          #+#    #+#             */
/*   Updated: 2022/02/04 17:31:02 by ddelladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_ptrnbrlen(size_t n, size_t b_len)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	while (n > 0)
	{
		n = n / b_len;
		i++;
	}
	return (i + 2);
}

char	*ft_utoa_base(size_t n, char *base, int b_len)
{
	char	*ret;
	int		len;

	len = ft_ptrnbrlen(n, b_len);
	ret = ft_calloc(len + 1, sizeof(char));
	if (!ret)
		return (0);
	ret[len--] = '\0';
	while (len >= 0)
	{
		ret[len] = base[n % b_len];
		n = n / b_len;
		len--;
	}
	ret[1] = 'x';
	return (ret);
}
