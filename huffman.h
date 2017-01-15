#ifndef HUFFMAN_H
#define HUFFMAN_H

#define LETTER_MAX 255

#include "tree.h"

typedef struct huffman_s huffman_s;

struct huffman_s
{
	unsigned char letter;
	int freq;
	char *code;
};

void huffman_table(node_s *root, char *code,  int index, huffman_s *table);

void huffman_normal_table(node_s *root, char *code, int index, huffman_s *table, int *letter);

void codage_huffman(int letter[LETTER_MAX], const char *input_file, const char *output_file);

#endif 
