#include <stdio.h>
#include "list.h"
#include "huffman.h"
#include "tree.h"
#include "read_file.h"



int main(int argc, char *argv[])
{
	if (argc > 1)
	{
		int letter[255] = {0};
		for (int i = 1; i < argc; i++)
		{
			read_file(argv[i], letter);
		        codage_huffman(letter);
		}
	}
	return 0;
}
