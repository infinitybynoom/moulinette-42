#include <stdio.h>
#include <stdlib.h>
#include "../ft_btree.h"

void	btree_apply_by_level(t_btree *root,
		void (*applyf)(void *item, int current_level, int is_last_level));

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

static void	print_level(void *item, int level, int is_last)
{
	printf("%s %d %d\n", (char *)item, level, is_last);
}

int	main(void)
{
	t_btree	*root;

	root = make_node("A");
	root->left = make_node("B");
	root->right = make_node("C");
	root->left->left = make_node("D");
	btree_apply_by_level(root, print_level);
	return (0);
}
