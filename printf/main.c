#include "libftprintf.h"
#include <limits.h>

int main()
{
	//int num = 300;
	//char c = 'r';
	int n;
	int p;
	
	//char *pru = ft_uint_itoa(UINT_MAX);
	//printf("pru:%s", pru);
	//ft_printf("esto es una prueba: %d", num);
	//n = ft_printf("esto es una prueba:%c<-;ahora el num:%d<-\n", c, num);
	//printf("esto es una prueba:%-5c<-;ahora el num:%-8d<-\n", c, num);
	//printf("->%d<-\n", UINT_MAX);
	printf("->%u<-\n", UINT_MAX);
	n = ft_printf("%2.2x<-\n", UINT_MAX);
	p = printf("%2.2x<-\n", UINT_MAX);
	//p = printf("%.d<-\n", 0);
	//printf("%-u<-\n", INT_MAX);
	//n = ft_printf("%*.1s<-\n", 10, "123");
	//p = printf("%*.1s<-\n", 10, "123");
	//p = printf("%*d", 0, num);
	printf("return ft_printf: %d\n", n);
	printf("return printf: %d\n", p);
	//system("leaks -fullContent a.out");
}