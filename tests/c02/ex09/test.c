#include <stdio.h>

char	*ft_strcapitalize(char *str);

int	main(void)
{
	char	s1[] = "salut, comment tu vas ? 42mots";
	char	s2[] = "hello world";

	printf("%s\n", ft_strcapitalize(s1));
	printf("%s\n", ft_strcapitalize(s2));
	return (0);
}
