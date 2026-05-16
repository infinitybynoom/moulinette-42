#include <stdio.h>

int	ft_strcmp(char *s1, char *s2);

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
	print_sign(ft_strcmp("abc", "abc"));
	print_sign(ft_strcmp("abc", "abd"));
	print_sign(ft_strcmp("abd", "abc"));
	print_sign(ft_strcmp("", ""));
	return (0);
}
