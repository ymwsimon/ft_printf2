

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	/*char c = 'E';
	char str[] = "-abcdefghijklmnopqrstuvwxyz-";
	//char nstr = 0;
	int	i = 20234878;
	int	h = 245235;
	int n = -400;
	char format[] = "char = %2c, str = %#-.20s, i = %010.5d, &i = %#p, h = % x, H = %  #X, n = % #+060.30u, percent = %%  \n";
	//char format2[] = "char = %c, str = %s, i = %d, &i = %p, h = %x, H = %X, n = %u, percent = %%  \n";
	int res;

	ft_printf("ft version : ");
	res = ft_printf(format, c, str, i, &i, h, h, n);
	ft_printf("length %d\n", res);
	ft_printf("ts version : \n");
	res = printf("test =char =%2c, str =%-.20s, i =% 020d, &i =%p, h =%x, H =%#X, n =%40.30u, percent =%%\n", c, str, i, &i, h, h, n);
	res = ft_printf("ftint=%10d\n", i);
	printf("length %d\n", res);
	res = printf("pfint=%20.10u-\n", i);
	printf("length %d\n", res);
	printf("test%s\n", str);*/
	int res;
	char str[50] = "abcdefghi";
	char	*t = 0;

	res = printf("og:=%20.0d=\n", 10);
	printf("length=%d\n", res);
	res = ft_printf("ft:=%20.0d=\n", 10);
	printf("length=%d\n", res);
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
