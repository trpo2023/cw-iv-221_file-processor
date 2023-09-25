#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

DIR* get_dir(char* dadres);
int check_input(char* adres);
void check_last_symbol(char* adres);