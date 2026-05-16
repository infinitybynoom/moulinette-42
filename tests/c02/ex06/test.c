#include <stdio.h>

int	ft_str_is_printable(char *str);

int	main(void)
{
	printf("%d\n", ft_str_is_printable("Hello, 42!"));
	printf("%d\n", ft_str_is_printable("Hello\t42"));
	printf("%d\n", ft_str_is_printable(""));
	return (0);
}
