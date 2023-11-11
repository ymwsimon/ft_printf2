

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
	char format[] = "char = %c, str = %s, i = %d, &i = %p, h = %x, n = %u, percent = %%  \n";
	char format2[] = "char = %c, str = %s, i = %d, &i = %p, h = %x, n = %u, percent = %%  \n";
	int res;

	ft_printf("ft version : ");
	res = ft_printf(format, c, str, i, &i, h, n);
	ft_printf("length %d\n", res);
	printf("og version : ");
	res = printf(format, c, str, i, &i, h, n);
	printf("length %d\n", res);
	printf("test% d\n", i);
	return (0);
}



/*include "ft_printf.h"
#include <stdio.h>

int	main()
{
	char a[] = "fwaef";
	char *b = 0;
	//ft_printf("ft_printf %s %d %i %c %u %x %X %p  %%\n", a, 0, -345, 65, -28, 40, -80, a);
	//ft_printf("ffff\n");
	//printf("test %p %d\n", a, 100);
	//printf("   printf !@#%d %d &%c %u %x %X %p  %%\n", 0, -345, 65, -28, 40, -80, a);
	//printf("   printf %s %d %i %c %u %x %X %p  %%\n", a, 0, -345, 65, -28, 40, -80, b);

	ft_printf("ft_printf%c%c%c%c%c\n", 0, '4', 0, '5', 0);

	printf("   printf%c%c%c%c%c\n", 0, '4', 0, '5', 0);
	return 0;
}
*/
