#include <stdio.h>

FILE* find_file(char* str);
void split_strings(char* s, char** s1, char** s2);
int make_arrays(FILE* f, char** m1, char** m2,  size_t* n);
void print_arr(char** m1, size_t n);