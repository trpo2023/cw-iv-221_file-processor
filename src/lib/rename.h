#include <stdio.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>

void find_ras(char* c);
void make_new_name(char* newname, char* c, int n, char* nras);
void rename_files(char* ras, char* name, DIR* dir, char* input);
