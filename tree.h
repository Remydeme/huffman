#ifndef TREE_H
#define TREE_H

#define LETTER_MAX 255


typedef struct node_s node_s;

struct node_s 
{
	int freq;
	node_s *l;
	node_s *r;
	unsigned char letter;
};

node_s *build_tree(int letter[LETTER_MAX], int *counter);


#endif 

