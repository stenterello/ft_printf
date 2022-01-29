#include "includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
	int	len;
	char	*null_str = NULL;
	int	c;

	c = 0;

	len = ft_printf(" |%04d| ", 9);
	printf("\n%d\n", len);
	len = printf(" |%04d| ", 9);
	printf("\n%d\n", len);
}
