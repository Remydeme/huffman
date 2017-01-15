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
			read_file(argv[1], letter);
		        codage_huffman(letter, argv[1], argv[2]);
	}
	return 0;
}
