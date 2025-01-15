/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisciane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:07:53 by nisciane          #+#    #+#             */
/*   Updated: 2025/01/15 15:12:30 by nisciane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_putchar(c)
{
	int	len;
	len = 0;

	write(1, &c, 1);
	len++;
	return (len);
}

void	ft_putstr(const char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

void	ft_putnbr(int n)
{
	if (n == - 2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n *= (-1);
	}
	if (n < 10)
	{
		ft_putchar(n + '0');
	}	
	else
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
}
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putuint(unsigned int n)
{
	
}
int	ft_printf(const char *format, ...)
{
	va_list list;
	va_start(list, format);
	char *string_to_print;
	int	dec_num_to_print;
	int	len_of_format;
	len_of_format = ft_strlen(format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
			{
				format++;
				ft_putchar('%');
				len_of_format -= 1;
			}
			else if (*format == 'c' || *format == 's')
			{	
				format++;
				string_to_print = va_arg(list, char*);
				ft_putstr(string_to_print);
				len_of_format -= 2;
				len_of_format += ft_strlen(string_to_print);
			}
			else if (*format == 'd' || *format == 'i')
			{
				format++;
				dec_num_to_print = va_arg(list, int);
				ft_putnbr(dec_num_to_print);
				len_of_format -= 2;
				printf("coucou %d",ft_putnbr(dec_num_to_print));
			}
		}
		ft_putchar(*format);
		format++;
	}
	va_end(list);
	printf("%d", len_of_format);
	return (len_of_format);
}
int	main(void)
{
	char *test1 = "hello %s, I'm %d";
	char *arg1 = "Jul";
	int	arg2 = 26;
	ft_printf(test1, arg1, arg2);
}


