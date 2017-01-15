#ifndef LIST_H
#define LIST_H

#define LETTER_MAX 255
#include "tree.h"


typedef struct list_s list_s;  

struct list_s
{
	node_s *node_t;
	list_s *next;
};


int is_empty(list_s *head);

list_s *list_pop(list_s *head);


node_s *list_peek(list_s *head);


list_s *insert_node(list_s *head, node_s *node);


list_s *init_list(void);

void print_list(list_s *head);

list_s *build_list(int letter[LETTER_MAX], int *counter);

#endif 
