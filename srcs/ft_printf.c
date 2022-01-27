#include "../includes/ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		counter;
	int		i;

	va_start(args, s);
	i = 0;
	counter = 0;
	while (*(s + i) != '\0')
	{
		if (ft_ispercent(s[i]) && s[i + 1])
		{
			i++;
			counter += ft_deep_elaborate(s, &i, args);
		}
		else
		{
			ft_putchar_fd(s[i], 1);
			counter += 1;
			i++;
		}
	}
	va_end(args);
	return (counter);
}
