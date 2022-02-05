#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>

int count = 0;
// write character
int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

void	ft_putnbr(long nb)
{
	//const int count = counter(nb, 10);

	if (nb < 0)
	{
		count += ft_putchar('-');	
		nb *= (-1);
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	count += ft_putchar((nb % 10) + 48);
//	return (count);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write (1, "(null)", 6);
		count += 6;
		return ;
	}
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
		count ++;
	}
//	return (count);
}


int ft_puthex(unsigned int nb)
{
//	const	int	count = counter(nb, 16);
	char	*hex;

	hex = "0123456789abcdef";
	if (nb > 15)
		ft_puthex(nb / 16);
	count += ft_putchar((hex[nb % 16]));
	return (count);
}

int	check_type(char c, va_list ap)
{

	if (c == 'd')
		ft_putnbr(va_arg(ap, int));
	if (c == 's')
		ft_putstr(va_arg(ap, char *));
	if (c == 'x')
		ft_puthex(va_arg(ap, unsigned int));
	return (count);
}
// this the ft_printf function
int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;

	if (count != 0)
		count = 0;
	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			check_type(format[i + 1], ap);
			i += 2;
		}
		else
		{

			count += ft_putchar(format[i]);
			i++;
		}
	}
	return (count);
}

// this the main function
/*
int	main()
{
	int	i;
	i = ft_printf("the number is %d and the string is %s\n", 2020, NULL);
	printf ("the counter is: %d\n", i);
	i = printf("the number is %d and the string is %s\n", 2020, NULL);
	printf ("the counter is: %d\n", i);

	i = ft_printf ("the number is : %x %x\n", INT_MIN, 166);
		printf ("%d\n", i);
	i = printf ("the number is : %x %x\n", INT_MIN, 166);
		printf ("%d\n", i);

}*/

