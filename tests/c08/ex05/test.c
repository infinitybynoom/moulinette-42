#include <stdio.h>
#include <stdlib.h>

typedef struct s_stock_str
{
	int		size;
	char	*str;
	char	*copy;
}	t_stock_str;

void	ft_show_tab(t_stock_str *tab);

int	main(void)
{
	t_stock_str	tab[4];
	char		copy0[] = "hello";
	char		copy1[] = "world";
	char		copy2[] = "42";

	tab[0].str = "hello";
	tab[0].size = 5;
	tab[0].copy = copy0;
	tab[1].str = "world";
	tab[1].size = 5;
	tab[1].copy = copy1;
	tab[2].str = "42";
	tab[2].size = 2;
	tab[2].copy = copy2;
	tab[3].str = NULL;
	tab[3].size = 0;
	tab[3].copy = NULL;
	ft_show_tab(tab);
	return (0);
}
