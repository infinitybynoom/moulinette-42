#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../ft_btree.h"

void	btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *));

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

static void	infix(t_btree *root)
{
	if (!root)
		return ;
	infix(root->left);
	printf("%s\n", (char *)root->item);
	infix(root->right);
}

static int	cmp_str(void *a, void *b)
{
	return (strcmp((char *)a, (char *)b));
}

int	main(void)
{
	t_btree	*root = NULL;

	(void)make_node;
	btree_insert_data(&root, "E", cmp_str);
	btree_insert_data(&root, "B", cmp_str);
	btree_insert_data(&root, "G", cmp_str);
	btree_insert_data(&root, "A", cmp_str);
	btree_insert_data(&root, "D", cmp_str);
	infix(root);
	return (0);
}
