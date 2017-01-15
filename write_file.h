#ifndef WRITTE_FILE_H
#define WRITTE_FILE_H

#include "huffman.h"

void write_file(huffman_s table[LETTER_MAX], FILE *input, FILE *output);

void huffman_file(const char *input_file, const char *output_file, huffman_s table[LETTER_MAX]);

#endif 
