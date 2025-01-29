/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisciane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:07:53 by nisciane          #+#    #+#             */
/*   Updated: 2025/01/29 19:14:25 by nisciane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_putchar(c)
{
	write(1, &c, 1);
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

void	ft_putuint(unsigned int n)
{
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	length_of(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}
/*void	ft_putptr(intptr_t num)
{
	if (num >= 16)
	{
		ft_putptr(num / 16);
		ft_putptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar(num + '0');
		else
			ft_putchar(num - 10 + '0');
	}
}
void	ft_printp(unsigned long long ptr)
{
	write(1, "0x", 2);
	if (ptr == 0)
		write(1, "0", 1);

	else
		ft_putptr(ptr);
}
*/
void	ft_putadd_hex(unsigned long int nbr, char Xx)
{
	unsigned long int	base_len;
	char   *base;

	base_len = 16;
	if (Xx == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nbr < base_len)
		ft_putchar(base[nbr % base_len]);
	else
	{
		ft_putadd_hex(nbr / base_len, Xx);
		ft_putadd_hex(nbr % base_len, Xx);
	}

}
void	ft_putadd(void *add)
{
	unsigned long int ptr;
	ptr = (unsigned long int)add;

	if (add == 0)
	{
		ft_putstr("(nil)");
	}
	else
	{
		ft_putstr("0x");
		ft_putadd_hex(ptr, 'x');
	}
}
int	ft_printf(const char *format, ...)
{
	va_list list;
	va_start(list, format);
	char *string_to_print;
	char 	char_to_print;
	int	dec_num_to_print;
	int	len_of_format;
	unsigned int	uint_to_print;
	void *p_to_print;

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
			else if (*format == 'c')
			{
				format++;
				char_to_print = va_arg(list, int);
				ft_putchar(char_to_print);
				len_of_format -= 1;

			}
			else if (*format == 's')
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
				len_of_format += length_of(dec_num_to_print);

			}
			else if (*format == 'u')
			{
				format++;
				uint_to_print = va_arg(list, unsigned int);
				ft_putuint(uint_to_print);
				len_of_format -= 2;
				len_of_format += length_of(uint_to_print);
					
			}
			else if (*format == 'p')
			{
				format++;
				p_to_print = va_arg(list, unsigned long long);
				ft_putadd(p_to_print);
				len_of_format -= 2;
				len_of_format += length_of(p_to_print);

			}
		}
		ft_putchar(*format);
		format++;
	}
	va_end(list);
	return (len_of_format);
}
/*int	main(void)
{
	char *test1 = "hello %c";
	char arg1 = 'j';
	char *test2 = "%u";
	unsigned int uint_test;
	uint_test = -1;
	//int	arg2 = 2147483647;
	//printf("test my function : len  = %d \n", ft_printf(test1, arg1));
	//printf("test c function %d", printf(test1, arg1));
	printf(test2, uint_test);
	ft_printf(test2, uint_test);
	printf("%p", -1);
}*/

