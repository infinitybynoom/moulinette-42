#include <stdio.h>
#include <unistd.h>
#include "ft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	main(void)
{
	int	a;
	int	b;

	a = 1;
	b = 2;
	ft_swap(&a, &b);
	printf("%d %d\n", a, b);
	printf("%d\n", ft_strlen("hello"));
	printf("%d\n", ft_strcmp("abc", "abc"));
	return (0);
}
