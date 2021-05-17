

void	ft_printf(char *str, ...)
{
	char *word;
	va_list	param;

	word = str;
	va_start(param, word);
	while (*word)
	{
		if (*word == '%')
		//ver de que tipo es con el siguiente caracter
		//por ejemplo si es un numero
		printf("(%d)", va_arg(param, int));
		else
			ft_putchar_fd(*word, 1);
	
	}
	va_end(param);

}
