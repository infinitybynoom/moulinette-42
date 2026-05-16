#include <stdio.h>

int	ft_strlen(char *str);

int	main(void)
{
	printf("%d\n", ft_strlen(""));
	printf("%d\n", ft_strlen("Hello, 42!"));
	printf("%d\n", ft_strlen("abc"));
	return (0);
}
