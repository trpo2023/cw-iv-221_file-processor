#include "opendir.h"
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char adres[100];
    DIR* dir = get_dir(adres);
    if (!dir) {
        return 1;
    }
    printf("YES\n");
    closedir(dir);

    return 0;
}