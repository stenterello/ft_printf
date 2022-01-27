#include "../includes/ft_printf.h"

char	*ft_binary_sum(char *bin)
{
	int i2;

	i2 = ft_strlen(bin);
	while (bin[i2] != -1)
	{
		if (bin[i2] == 0)
		{
			bin[i2] = 1;
			return (bin);
		}
		if (bin[i2] == 1)
		{
			bin[i2] = 0;
			while (bin[i2 - 1] == 1)
			{
				bin[i2 - 1] = 0;
			}
			return (bin);
		}
		i2--;
	}
	return (bin);
}

char	*ft_negative_hex(int nbr)
{
	int		i;
	char	*bin;

	i = 0;
	while (nbr != 1)
	{
		bin[i] = nbr / 2;
		i++;
	}
	bin[i] = nbr / 2;
	bin[i + 1] = '\0';
	i = 0;
	while (bin[i])
	{
		if (bin[i] == 0)
			bin[i] = 1;
		else
			bin[i] = 0;
	}
	bin = ft_binary_sum(bin);
	return (bin);
}