#include <stdio.h>

int	ft_str_is_numeric(char *str);

int	main(void)
{
	printf("%d\n", ft_str_is_numeric("12345"));
	printf("%d\n", ft_str_is_numeric("123a5"));
	printf("%d\n", ft_str_is_numeric(""));
	printf("%d\n", ft_str_is_numeric("0"));
	return (0);
}
