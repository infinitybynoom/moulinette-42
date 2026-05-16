#include <stdio.h>

char	*ft_strnstr(char *str, char *to_find, unsigned int n);

int	main(void)
{
	char	*r;

	r = ft_strnstr("Hello, 42!", "42", 10);
	printf("%s\n", r ? r : "NULL");
	r = ft_strnstr("Hello, 42!", "42", 6);
	printf("%s\n", r ? r : "NULL");
	r = ft_strnstr("abc", "", 3);
	printf("%s\n", r ? r : "NULL");
	return (0);
}
