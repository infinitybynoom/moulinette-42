#include <stdio.h>

int	ft_is_prime(int nb);

int	main(void)
{
	printf("%d\n", ft_is_prime(0));
	printf("%d\n", ft_is_prime(1));
	printf("%d\n", ft_is_prime(2));
	printf("%d\n", ft_is_prime(7));
	printf("%d\n", ft_is_prime(9));
	printf("%d\n", ft_is_prime(-5));
	return (0);
}
