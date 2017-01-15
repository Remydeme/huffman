#include <stdlib.h>
#include <stdio.h>
#include "list.h"

list_s *init_list(void)
{
	return NULL;
}

list_s *insert_node(list_s *head, node_s *node)
{
	if (!head)
	{

                list_s *list_node = calloc (1, sizeof (list_s));
		if (list_node)
			list_node->node_t = node;
		return list_node;
	}
	else if  (node->freq < head->node_t->freq)
	{
		list_s *list_node  = calloc (1, sizeof (list_s));
			if (list_node)
				list_node->node_t = node;
		list_node->next = head;
		return list_node; 
	}
	else
	{
		list_s *current_node = head->next;
		list_s *prec_node = head;
		while (current_node != NULL)
		{
			if (node->freq < current_node->node_t->freq)
			{
				 prec_node->next = calloc(1 , sizeof (list_s));
				 if (prec_node->next)
					 prec_node->next->node_t = node;
				 prec_node->next->next = current_node;
				 break;
			}
			prec_node = current_node;
			current_node = current_node->next;
		}

		if (!current_node && prec_node)
		{
			prec_node->next = calloc(1, sizeof (list_s));
			if (prec_node->next)
				prec_node->next->node_t = node;
		}
		return head;
	}
}


int is_empty(list_s *head)
{
	if (head && head->next)
		return 0;
	return 1;
}

node_s *list_peek(list_s *head)
{
	return head->node_t;
}


list_s *list_pop(list_s *head)
{
	if (head)
	{
		list_s *tmp = head->next;
		free(head);
		return tmp; 
	}
	return NULL;
}

void print_list(list_s *head)
{
	if (head)
	{
		printf(" frequence %d value : %c ", head->node_t->freq, head->node_t->letter);
		print_list(head->next);
	}
}


list_s *build_list(int letter[LETTER_MAX], int *counter)
{
	list_s *list = init_list();
	if (letter)
	{
		for (int i = 0  ; i < LETTER_MAX; i++)
			if (letter[i])
			{
				(*counter)++; 
				node_s *node = calloc (1, sizeof (node_s));
				node->freq = letter[i];
				node->letter = i;
				list = insert_node(list, node);
			}
	}
	return list;
}
