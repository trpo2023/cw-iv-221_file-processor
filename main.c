#include "rename.h"
#include "opendir.h"
#include <stdio.h>
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
int main()
{


    char* ras[] = {"txt", "png"};
    char* newname[] = {"TEXTFILE", "Photo"};
    size_t n = 2;

    char input[256];
    DIR* dir = get_dir(input);
    if (!dir) {
        return 1;
    }

    for(int i=0; i<n; i++){
        rename_files(ras[i], newname[i], dir, input);
    } 
    
    
    return 0;
}
