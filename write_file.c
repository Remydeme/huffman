#include <stdio.h>
#include <assert.h>
#include "write_file.h"




void write_file(huffman_s table[LETTER_MAX], FILE *input, FILE *output)
{
	assert(input != NULL);
	assert(output != NULL);
	int c; 
	while ((c = fgetc(input)) != EOF)
		fprintf(output, "%s", table[c].code);
}


void huffman_file(const char *input_file, const char *output_file, huffman_s table[LETTER_MAX])
{
	assert(output_file != NULL);
	assert(input_file != NULL);
	assert(table != NULL);
	FILE *input = fopen(input_file, "r");
	if (input)
	{
		FILE *output = fopen(output_file, "w");
		if (output)
			write_file(table, input, output);
	}
}
