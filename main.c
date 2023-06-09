#include "rename.h"
#include <stdio.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>
int main()
{

    DIR *dir; 

    char* ras[] = {"txt", "png"};
    char* newname[] = {"TEXTFILE", "Photo"};
    char *input = "/home/an/files for rename/";
    size_t n = 2;

    dir = opendir(input);
    if (dir == NULL)
    {
        perror("Cannot open");
        return -1;
    }


    for(int i=0; i<n; i++){
        rename_files(ras[i], newname[i], dir, input);
    } 
    
    
    return 0;
}
