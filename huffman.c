#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "huffman.h" 


void huffman_table(node_s *root, char *code, int index, huffman_s *table, int *letter)
{
	if (root)
	{
		code[index] = root->tag;
		if (!root->l && !root->r)
		{
			table[*letter].letter = root->letter;
			table[*letter].code = calloc (1, sizeof (index));
			strncpy(table[*letter].code, code, index);
			(*letter)++;
		}
		huffman_table(root->l, code, index + 1, table, letter);
		huffman_table(root->r, code, index + 1, table, letter);
	}
}

void codage_huffman(int letter[LETTER_MAX])
{
	int counter = 0; 
	int index_table = 0;
	char code[8];
	node_s *root = build_tree(letter, &counter);
	huffman_s *table = calloc (counter, sizeof (huffman_s));
	huffman_table(root, code, 0, table, &index_table);
	for (int i = 0; i < counter; i++)
		printf (" freq  : %d letter : %d code %s", table[i].freq, table[i].letter, table[i].code);
}

