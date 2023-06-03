#include "scanfile.h"
#include <stdlib.h>

int main(int argc, char* argv[]){
    // argc - кол-во аргументов. Зависи от вызова функции
    // argv - сохраняет эти аргументы
    
    
    char** m1; //массив расширений
    char** m2; //массив шаблонов
    m1 = malloc ( 256 * sizeof( char *) );
    m2 = malloc ( 256 * sizeof( char *) );
    
    size_t n=0;// кол-во строк

    FILE* f=find_file(argv[1]);
    if(f && m1 && m2){//если всё открылось
        make_arrays(f, m1, m2, &n);//заполняем массивы
        print_arr(m1,n);
        print_arr(m2,n);
    }
    // printf("%s\n", m1[0]);
}