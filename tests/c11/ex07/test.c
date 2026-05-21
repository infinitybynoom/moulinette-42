#include <stdio.h>
#include <string.h>

void	ft_advanced_sort_string_tab(char **tab, int size, int (*cmp)(char *, char *));

int	main(void)
{
	char	*tab[] = {"cherry", "apple", "banana", "date", NULL};
	int		i;

	ft_advanced_sort_string_tab(tab, 4, &strcmp);
	i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	return (0);
}
