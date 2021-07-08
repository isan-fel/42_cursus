#include "libftprintf.h"
#include <limits.h>

int main()
{
	//int num = 300;
	//char c = 'r';
	int n = 0;
	int p = 0;
	//static char	*a01;
	//static char *s_hidden = "hi low\0 don't print me lol\0";
	//char *pru = ft_uint_itoa(UINT_MAX);
	//printf("pru:%s", pru);
	//ft_printf("esto es una prueba: %d", num);
	//n = ft_printf("esto es una prueba:%c<-;ahora el num:%d<-\n", c, num);
	//printf("esto es una prueba:%-5c<-;ahora el num:%-8d<-\n", c, num);
	//printf("->%lu<-\n", LONG_MIN);
	//printf("->%ld<-\n", -ULONG_MAX);
	//printf("->%.x<-\n", 0);
	//n = ft_printf("%.03d<-\n", 234);
	//p = printf("%.03d<-\n");
	//n = ft_printf("%p<-\n", (void *)344);
	//p = printf("%p<-\n", (void *)344);
	//p = printf("%.d<-\n", 0);
	//printf("%-u<-\n", INT_MAX);
	//n = ft_printf("%.9s<-\n", NULL);
	//p = printf("%.9s<-\n", NULL);
	n = ft_printf("->%% *.5i 42 == |%.*d|<-\n", -4, 42);
	p = printf("->%% *.5i 42 == |%.*d|<-\n", -4, 42);
	printf("return ft_printf: %d\n", n);
	printf("return printf: %d\n", p);
	//system("leaks -fullContent a.out");
	//free(pru);
}