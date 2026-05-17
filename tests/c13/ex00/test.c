#include <stdio.h>
#include <stdlib.h>
#include "../ft_btree.h"

t_btree	*btree_create_node(void *item);

int	main(void)
{
	t_btree	*node;

	node = btree_create_node("hello");
	printf("%s\n", (char *)node->item);
	printf("%s\n", node->left == NULL ? "left NULL" : "left set");
	printf("%s\n", node->right == NULL ? "right NULL" : "right set");
	free(node);
	return (0);
}
