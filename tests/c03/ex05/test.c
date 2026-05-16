#include <stdio.h>

char	*ft_strstr(char *str, char *to_find);

int	main(void)
{
	char	*r;

	r = ft_strstr("Hello, 42!", "42");
	printf("%s\n", r ? r : "NULL");
	r = ft_strstr("Hello", "world");
	printf("%s\n", r ? r : "NULL");
	r = ft_strstr("abc", "");
	printf("%s\n", r ? r : "NULL");
	return (0);
}
