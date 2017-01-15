#ifndef READ_FILE_H
#define READ_FILE_H
#include <stdio.h>


#define LETTER_MAX 255

void get_frequency(int letter[255], FILE *stream);

void display_frequency(const int letter[255]);

void read_file(const char *file_name, int letter[255]);

FILE *open_file(const char *file_name);

#endif 
