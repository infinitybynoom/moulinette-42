#include <stdio.h>

int	ft_strlen(char *str);

int	main(void)
{
	printf("%d\n", ft_strlen(""));
	printf("%d\n", ft_strlen("Hello"));
	printf("%d\n", ft_strlen("42 is the answer"));
	printf("%d\n", ft_strlen("abc"));
	return (0);
}
