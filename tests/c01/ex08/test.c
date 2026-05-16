#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size);

int	main(void)
{
	int	tab[6] = {5, 3, 1, 4, 2, 0};
	int	i;

	ft_sort_int_tab(tab, 6);
	i = 0;
	while (i < 6)
		printf("%d ", tab[i++]);
	printf("\n");
	return (0);
}
