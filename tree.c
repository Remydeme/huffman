#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

node_s *add_node_tree(list_s *list)
{
	while (!is_empty(list))
	{
		node_s *left_node = list_peek(list);
		list = list_pop(list);
		node_s *right_node = list_peek(list);
		list = list_pop(list);
		node_s *root = calloc(1, sizeof (node_s));
		root->l = left_node;
		left_node->tag = '0'; 
		root->r = right_node;
		right_node->tag = '1';
		root->freq = right_node->freq + left_node->freq;
		list = insert_node(list, root);
	}
	node_s * root = list->node_t;
	free(list);
	return root;
}

void print_tree(node_s *root)
{
	if (root)
	{
		printf ("tag %c , frequency : %d ", root->tag, root->freq);
		if (!root->l && !root->r)
			printf ("|| letter : %c  ||", root->letter);
		printf ("\n");
		print_tree(root->l);
		print_tree(root->r);
	}
}


node_s *build_tree(int letter[LETTER_MAX], int *counter)
{
	list_s *list = build_list(letter, counter);
	print_list(list);
	node_s *root = add_node_tree(list);
	print_tree(root);
	return root;
}
