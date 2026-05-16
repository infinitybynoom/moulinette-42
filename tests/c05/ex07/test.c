#include <stdio.h>

int	ft_find_next_prime(int nb);

int	main(void)
{
	printf("%d\n", ft_find_next_prime(0));
	printf("%d\n", ft_find_next_prime(2));
	printf("%d\n", ft_find_next_prime(5));
	printf("%d\n", ft_find_next_prime(9));
	printf("%d\n", ft_find_next_prime(14));
	return (0);
}
