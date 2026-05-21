#include <stdio.h>
#include <stdlib.h>
#include "../ft_btree.h"

int	btree_level_count(t_btree *root);

static t_btree	*make_node(void *item)
{
	t_btree	*n = malloc(sizeof(t_btree));
	if (!n)
		return (NULL);
	n->item = item;
	n->left = NULL;
	n->right = NULL;
	return (n);
}

int	main(void)
{
	t_btree	*root;

	printf("%d\n", btree_level_count(NULL));
	root = make_node("A");
	printf("%d\n", btree_level_count(root));
	root->left = make_node("B");
	root->right = make_node("C");
	printf("%d\n", btree_level_count(root));
	root->left->left = make_node("D");
	printf("%d\n", btree_level_count(root));
	return (0);
}
