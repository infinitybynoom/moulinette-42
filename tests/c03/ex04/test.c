#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n);

static void	print_sign(int n)
{
	if (n < 0)
		printf("-\n");
	else if (n > 0)
		printf("+\n");
	else
		printf("0\n");
}

int	main(void)
{
	print_sign(ft_strncmp("abcdef", "abcxyz", 3));
	print_sign(ft_strncmp("abcdef", "abcxyz", 4));
	print_sign(ft_strncmp("abc", "abc", 100));
	return (0);
}
