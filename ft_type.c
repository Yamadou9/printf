#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

int	ft_itoa(int n, char *base, int count);
int	ft_putnbr(long long d, int count);
int	ft_itoavoid(void *n, char *base, int count);

int	ft_putstr(char *s, int count)
{
	int	i;

	i = 0;
	while (s[i])
		write(1, &s[i++], 1);
	count += i;
	return (count);
}

int	ft_putchar(int c, int count)
{
	write(1, &c, 1);
	return(count + 1);
}

typedef struct ft_type
{
	long long	d;
	unsigned long long l;
	char *str;
	char c;
	void *v;
} s_point;

int	is_format(char c)
{
	char *format;
	int		i;

	i = 0;
	format = "cspdiuxX";
	while (format[i])
	{
		if (c == format[i])
			return (1);
		i++;
	}
	return (0);
}
int ft_printf(const char	*s, ...)
{
	int		i;
	int		count;
	va_list ar;
	s_point t;

	i = 0;
	count = 0;
	va_start(ar, s);
	while(s[i])
	{
		if (s[i] == '%' && (s[i + 1] == 's'))
		{
			t.str = (char *)va_arg(ar, char *);
			count = ft_putstr(t.str, count);
		}
		else if (s[i] == '%' && (s[i + 1] == 'c'))
		{
			t.d = va_arg(ar, int);
			count = ft_putchar(t.d, count);
		}
		else if (s[i] == '%' && (s[i + 1] == 'd' || s[i + 1] == 'i' || s[i + 1] == 'u'))
		{
			t.d = (long long)va_arg(ar, long long);
			count = ft_putnbr(t.d, count);
		}
		else if (s[i] == '%' && s[i + 1] == 'x')
		{
			t.d = (int)va_arg(ar, int);
			count = ft_itoa(t.d, "0123456789abcdef", count);
		}
		else if (s[i] == '%' && s[i + 1] == 'X')
		{
			t.d = (int)va_arg(ar, int);
			count = ft_itoa(t.d, "0123456789ABCDEF", count);
		}
		else if (s[i] == '%' && s[i + 1] == 'p')
		{
			t.v = va_arg(ar, void *);
			write(1, "0x", 2);
			count = ft_itoavoid(t.v, "0123456789abcdef", count) + 2;
		}
		else if (s[i] == '%' && s[i + 1] == '%')
		{
			write(1, &s[i + 1], 1);
			count++;
			i++;
		}
		else if (s[i - 2] == '%' && s[i - 1] == '%' && is_format(s[i]))
		{
			write(1, &s[i], 1);
			count++;
		}
		else if (s[i - 1] == '%' && is_format(s[i]))
			;
		else
		{
			write(1, &s[i], 1);
			count++;
		}
		i++;
	}
	return (count);
}
int	main()
{
	char	*ko;
	char c = 'd';
	unsigned int		n = 0xff;
	char *s;
	s = "bonjour";
	ko = "oul";
	ft_printf("gfhyvvcgi %s", s);
}
