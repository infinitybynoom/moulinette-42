#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref,
		int (*cmpf)(void *, void *));

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

static int	cmp_str(void *a, void *b)
{
	return (strcmp((char *)a, (char *)b));
}

int	main(void)
{
	t_btree	*root;
	void	*result;

	root = make_node("E");
	root->left = make_node("B");
	root->right = make_node("G");
	root->left->left = make_node("A");
	root->left->right = make_node("D");
	result = btree_search_item(root, "B", cmp_str);
	printf("%s\n", result ? (char *)result : "NULL");
	result = btree_search_item(root, "Z", cmp_str);
	printf("%s\n", result ? (char *)result : "NULL");
	return (0);
}
