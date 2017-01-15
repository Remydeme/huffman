#include <stdio.h>
#include <errno.h>
#include <assert.h>
#include "read_file.h"


void get_frequency(int letter[255], FILE *stream)
{
	assert(stream != NULL);
	assert(letter != NULL);
	int c = 0;
	while ((c = fgetc(stream)) != EOF)
		letter[c]++; 
}


void display_frequency(const int letter[255])
{
	for (int i = 0; i < LETTER_MAX; i++)
		if (letter[i])
			printf("Letter : %c : frequencny : %d. \n", i, letter[i]);  
}

void read_file(const char *file_name, int letter[255])
{
	FILE *stream = open_file(file_name);
	get_frequency(letter, stream);
	fclose(stream);
	display_frequency(letter);
}


FILE *open_file(const char *file_name)
{
	if (file_name)
	{
		FILE *stream = fopen(file_name, "r");
		if (!stream)
			perror("fopen :");
		return stream;
	}
	return NULL;
}

