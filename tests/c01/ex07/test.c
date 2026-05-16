#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size);

int	main(void)
{
	int	tab1[5] = {1, 2, 3, 4, 5};
	int	tab2[3] = {-1, 0, 42};
	int	i;

	ft_rev_int_tab(tab1, 5);
	i = 0;
	while (i < 5)
		printf("%d ", tab1[i++]);
	printf("\n");
	ft_rev_int_tab(tab2, 3);
	i = 0;
	while (i < 3)
		printf("%d ", tab2[i++]);
	printf("\n");
	return (0);
}
