#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
Dir* open_dir(char* dadres){
    printf("input dir: ");
    scanf("%s", dadres);
    printf("%s\n", dadres);
    DIR* dir = opendir(dadres);
    if(!dir) {
        perror("opendir");
        return NULL;
    }
    return dir;
}
int main()
{
    char adres[100];
    DIR* dir = open_dir(adres);
    if (dir) {
        printf("YES");
        closedir(dir);
    }

    return 0;
}
