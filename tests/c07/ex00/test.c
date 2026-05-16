#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strdup(char *src);

int	main(void)
{
	char	*dup;

	dup = ft_strdup("Hello, 42!");
	printf("%s\n", dup);
	printf("%d\n", (int)strcmp(dup, "Hello, 42!") == 0);
	free(dup);
	dup = ft_strdup("");
	printf("[%s]\n", dup);
	free(dup);
	return (0);
}
