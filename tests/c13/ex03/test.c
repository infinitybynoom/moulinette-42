#include <stdio.h>
#include <stdlib.h>
#include "../ft_btree.h"

t_btree	*btree_create_node(void *item);
void	btree_apply_suffix(t_btree *root, void (*applyf)(void *));

static void	print_item(void *item)
{
	printf("%s\n", (char *)item);
}

int	main(void)
{
	t_btree	*root;

	root = btree_create_node("A");
	root->left = btree_create_node("B");
	root->right = btree_create_node("C");
	root->left->left = btree_create_node("D");
	root->left->right = btree_create_node("E");
	btree_apply_suffix(root, print_item);
	return (0);
}
