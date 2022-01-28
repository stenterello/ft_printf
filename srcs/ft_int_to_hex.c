#include "../includes/ft_printf.h"

int	ft_abs_val(int data)
{
	if (data < 0)
		return (-data);
	return (data);
}

char	*ft_int_to_bin(int data)
{
	char	*ret;
	int		i;

	ret = malloc(sizeof(char) * 33);
	ret[32] = '\0';
	i = 31;
	while (i >= 0)
	{
		ret[i] = ft_abs_val(data) % 2 + 48;
		data /= 2;
		i--;
	}
	return (ret);
}

char	*ft_reverse_bin(char *convert)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		if (convert[i] == '0')
			convert[i] = '1';
		else
			convert[i] = '0';
		i++;
	}
	return (convert);
}

char	*ft_add_one_to_bin(char *convert, int pos)
{
	if (convert[pos] == '1')
	{
		convert[pos] = '0';
		if (pos > 0)
			convert = ft_add_one_to_bin(convert, --pos);
	}
	else
		convert[pos] = '1';
	return (convert);
}

int	ft_power(int base, int esp)
{
	int	result;

	result = 1;
	if ((base == 0) || esp < 0)
		return (0);
	if ((esp == 0) || ((base < 0) && (esp == 0)))
		return (1);
	else
	{
		while (esp > 0)
		{
			result = base * result;
			esp--;
		}
		return (result);
	}
}

int	ft_atoi_char(char c)
{
	return (c - 48);
}

char	*ft_dec_to_hex(int *values, char *base)
{
	int		i;
	char	*pr;

	i = 0;
	pr = ft_calloc(9, sizeof(char));
	while (i < 8)
	{
		pr[i] = base[values[i] % 16];
		i++;
	}
	pr[8] = '\0';
	return (pr);
}

char	*ft_bin_to_hex(char *convert, char *base)
{
	int		i;
	int		i2;
	int		j;
	int		values[8];

	i = 3;
	i2 = 0;
	j = 0;
	while (j < 8)
		values[j++] = 0;
	j = 0;
	while (j < 32)
	{
		while (i >= 0)
		{
			values[i2] += ft_power(ft_atoi_char(convert[j]) * 2, i);
			j++;
			i--;
		}
		i = 3;
		i2++;
	}
	return (ft_dec_to_hex(values, base));
}
