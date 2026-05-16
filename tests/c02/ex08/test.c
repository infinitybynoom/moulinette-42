#include <stdio.h>

char	*ft_strlowcase(char *str);

int	main(void)
{
	char	s1[] = "HELLO WORLD";
	char	s2[] = "Hello, 42!";

	printf("%s\n", ft_strlowcase(s1));
	printf("%s\n", ft_strlowcase(s2));
	return (0);
}
