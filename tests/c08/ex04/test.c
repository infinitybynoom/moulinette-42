#include <stdio.h>
#include <stdlib.h>

typedef struct s_stock_str
{
	int		size;
	char	*str;
	char	*copy;
}	t_stock_str;

t_stock_str	*ft_strs_to_tab(int ac, char **av);

int	main(void)
{
	char		*strs[] = {"hello", "world", "42", NULL};
	t_stock_str	*tab;
	int			i;

	tab = ft_strs_to_tab(3, strs);
	if (!tab)
		return (1);
	i = 0;
	while (tab[i].str)
	{
		printf("%s\n", tab[i].str);
		printf("%d\n", tab[i].size);
		printf("%s\n", tab[i].copy);
		i++;
	}
	free(tab);
	return (0);
}
