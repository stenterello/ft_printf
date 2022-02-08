/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 19:40:04 by ddelladi          #+#    #+#             */
/*   Updated: 2022/02/01 19:40:05 by ddelladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_add_data_percent(char *ret, t_print *arg)
{
	int	i;

	i = 0;
	if (arg->zero && arg->width > 1)
	{
		while (i < arg->width - 1)
			ret[i++] = '0';
		ret[i] = '%';
	}
	else if (arg->width > 1)
	{
		while (i < arg->width - 1)
			ret[i++] = '0';
		ret[i] = '%';
	}
}

int	ft_no_flag_percent(void)
{
	ft_putstr_fd("%", 1);
	return (1);
}

char	*ft_create_str_percent(t_print *arg)
{
	char	*ret;

	if (arg->width > 1 && arg->width > arg->prec)
		ret = ft_calloc(arg->width, sizeof(char));
	else if (arg->prec > 1 && arg->prec > arg->width)
		ret = ft_calloc(arg->prec, sizeof(char));
	else
		return (NULL);
	return (ret);
}

int	ft_treat_percent(t_print *arg)
{
	char	*ret;
	int		count;

	ret = ft_create_str_percent(arg);
	if (!ret)
		return (ft_no_flag_percent());
	ft_add_data_percent(ret, arg);
	ft_putstr_fd(ret, 1);
	count = ft_strlen(ret);
	free(ret);
	return (count);
}
