#include <stdio.h>

int	ft_atoi(char *str);

int	main(void)
{
	printf("%d\n", ft_atoi("42"));
	printf("%d\n", ft_atoi("   -42abc"));
	printf("%d\n", ft_atoi("0"));
	printf("%d\n", ft_atoi("2147483647"));
	printf("%d\n", ft_atoi("-2147483648"));
	printf("%d\n", ft_atoi("   +42"));
	return (0);
}
