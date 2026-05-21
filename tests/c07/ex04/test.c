#include <stdio.h>
#include <stdlib.h>

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

int	main(void)
{
	char	*result;

	result = ft_convert_base("42", "0123456789", "01");
	printf("%s\n", result);
	free(result);
	result = ft_convert_base("101010", "01", "0123456789ABCDEF");
	printf("%s\n", result);
	free(result);
	result = ft_convert_base("-ff", "0123456789abcdef", "0123456789");
	printf("%s\n", result);
	free(result);
	return (0);
}
