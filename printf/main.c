#include "libftprintf.h"
#include <limits.h>

int main()
{
	//int num = 300;
	//char c = 'r';
	int n;
	int p;
	//ft_printf("esto es una prueba: %d", num);
	//n = ft_printf("esto es una prueba:%c<-;ahora el num:%d<-\n", c, num);
	//printf("esto es una prueba:%-5c<-;ahora el num:%-8d<-\n", c, num);
	printf("->%d<-\n", UINT_MAX + 1);
	n = ft_printf("%09.1d<-\n", UINT_MAX + 1);
	p = printf("%09.1d<-\n", UINT_MAX + 1);
	//n = ft_printf("%*.1s<-\n", 10, "123");
	//p = printf("%*.1s<-\n", 10, "123");
	//p = printf("%*d", 0, num);
	printf("return ft_printf: %d\n", n);
	printf("return printf: %d\n", p);
	//system("leaks -fullContent a.out");
}