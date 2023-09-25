#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>

void find_ras(char* c);
void make_new_name(char* newname, char* c, int n, char* nras);
void rename_files(char* ras, char* name, DIR* dir, char* input);
