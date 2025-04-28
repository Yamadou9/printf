#ifndef PRINTF_H
# define PRINTF_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdint.h>

int	ft_itoa(int n, char *base, int count);
int	ft_putnbr(long long d, int count);
int	ft_itoavoid(void *n, char *base, int count);
int	ft_putstr(char *s, int count);
int	ft_putchar(int c, int count);
int	is_format(char c);
int ft_printf(const char	*s, ...);

#endif

