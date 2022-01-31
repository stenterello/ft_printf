#include "includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
	int	len;
	char	*null_str = NULL;
	int	c;

	c = 0;

	len = ft_printf("%-10.d|", 0);
	printf("\n%d\n", len);
	len = printf("%-10.d|", 0);
	printf("\n%d\n", len);
}
