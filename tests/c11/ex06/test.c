#include <stdio.h>

void	ft_sort_string_tab(char **tab, int size);

int	main(void)
{
	char	*tab[] = {"cherry", "apple", "banana", "date", NULL};
	int		i;

	ft_sort_string_tab(tab, 4);
	i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	return (0);
}
