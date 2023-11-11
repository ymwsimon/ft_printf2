#include "ft_printf.h"
#include <stdio.h>

int	main(int arc, char **arv)
{
	char c = '\0';
	char str[] = "-1234-";
	char nstr = 0;
	int	i = 20;
	int	h = 245235;
	int n = -400;
		char format[] = "char = %c, str = %s, i = %d, &i = %p, h = %x, n = %u, percent = %% %v \n";
	int res;

	ft_printf("ft version : ");
	res = ft_printf(format, c, str, i, &i, h, n);
	ft_printf("length %d\n", res);
	printf("og version : ");
	res = printf(format, c, str, i, &i, h, n);
	printf("length %d\n", res);
	return (0);
}
