#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n);

int	main(void)
{
	char	dst[64];
	int		i;

	ft_strncpy(dst, "Hello", 5);
	dst[5] = '\0';
	printf("[%s]\n", dst);
	ft_strncpy(dst, "Hi", 10);
	printf("[%s]\n", dst);
	i = 0;
	while (i < 10)
	{
		printf("%d", (unsigned char)dst[i]);
		i++;
	}
	printf("\n");
	return (0);
}
