#include <stdio.h>

char	*ft_strupcase(char *str);

int	main(void)
{
	char	s1[] = "hello world";
	char	s2[] = "Hello, 42!";

	printf("%s\n", ft_strupcase(s1));
	printf("%s\n", ft_strupcase(s2));
	return (0);
}
