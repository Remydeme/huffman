#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "write_file.h"


void huffman_normal_table(node_s *root, char *code, int index, huffman_s *table, int *letter)
{
	if (root)
	{
		if (!root->l && !root->r)
		{
			table[*letter].letter = root->letter;
		        table[*letter].freq = root->freq;
			table[*letter].code = calloc (1, sizeof (index));
			strncpy(table[*letter].code, code, index);
			puts(table[*letter].code);
			(*letter)++;
		}
		code[index] = '0';
		huffman_normal_table(root->l, code, index + 1, table, letter);
		code[index] = '1';
		huffman_normal_table(root->r, code, index + 1, table, letter);
	}
}

void huffman_table(node_s *root, char *code, int index,  huffman_s *table)
{
	if (root)
	{
		if (!root->l && !root->r)
		{
			table[root->letter].letter = root->letter;
		        table[root->letter].freq = root->freq;
			table[root->letter].code = calloc (1, sizeof (index));
			strncpy(table[root->letter].code, code, index);
			puts(table[root->letter].code);// affichage a supprimmer 
		}
		code[index] = '0';
		huffman_table(root->l, code, index + 1, table);
		code[index] = '1';
		huffman_table(root->r, code, index + 1, table);
	}
}


void codage_huffman(int letter[LETTER_MAX], const char *input_file, const char *output_file)
{
	int counter = 0; 
	char code[50];
	node_s *root = build_tree(letter, &counter);
	huffman_s *table = calloc (LETTER_MAX, sizeof (huffman_s));
	huffman_table(root, code, 0, table);
	huffman_file(input_file, output_file, table);
}

