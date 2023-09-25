#include "lib/rename.h"
#include "lib/opendir.h"
#include "lib/scanfile.h"
#include <stdio.h>
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>

int main(int argc, char* argv[]){
    // argc - кол-во аргументов. Зависи от вызова функции
    // argv - сохраняет эти аргументы
    char** ras; //массив расширений
    char** newname; //массив шаблонов
    ras = malloc ( 256 * sizeof( char *) );
    newname = malloc ( 256 * sizeof( char *) );
    
    size_t n=0;// кол-во элементов
    FILE* f=find_file(argv[1]);
    if(f && ras && newname){//если всё открылось
        make_arrays(f, ras, newname, &n);//заполняем массивы
        printf("file readed successfully\n");
    }

    printf("Please input path to folder with files\n");
    char input[256];
    DIR* dir = get_dir(input);
    if (!dir) {
        return 1;
    }

    printf("Renaming files:\n");
    for(int i=0; i<n; i++){
        rename_files(ras[i], newname[i], dir, input);
    }
    printf("renaming is finished. \n");
}

