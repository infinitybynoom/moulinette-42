#include <stdio.h>
#include <stdlib.h>

char	*ft_strjoin(int size, char **strs, char *sep);

int	main(void)
{
	char	*words[] = {"Hello", "World", "42"};
	char	*result;

	result = ft_strjoin(3, words, ", ");
	printf("%s\n", result);
	free(result);
	result = ft_strjoin(1, words, "--");
	printf("%s\n", result);
	free(result);
	return (0);
}
