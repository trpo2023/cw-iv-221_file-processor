#include "rename.h"
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
int main(){

    DIR* dir;
    struct dirent *dp;
    dir = opendir ("pp");
    if(dir == NULL){
        perror("Cannot open");
        return 1;
    }
    while ((dp = readdir(dir)) != NULL) {
             printf ("[%s]\n", dp->d_name);
    }
    char ras[]={'.txt', '.png'};
    char newname[]= {'txt1', 'png1'};


    closedir(dir);
    return 0;

    
    
}
