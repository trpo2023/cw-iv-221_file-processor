#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE* find_file(char* str){//открываем файл
    FILE* f;//открываем файл
    f = fopen(str, "r");

    if (f == NULL) {
        printf("no such file in directory \n");
        return NULL;
    }
    return f;
}

void split_strings(char* s, char** s1, char** s2){//разделяет строку
    *s2=strtok(s," ");//выделяем расширение
    *s1=*s2;//копируем значение
    *s2=strtok(NULL," ");//продолжаем, выдел имя
    if(strchr(*s2, '\n'))//убираем спуски строки
        *s2=strtok(*s2,"\n");
    // printf("%c\n", s[0]);
    if(*s1[0]==46)
        (*s1)++;//убираем точки из расширений
    // printf("%s%s\n", s1,s2);
}

void make_arrays(FILE* f, char** m1, char** m2,  size_t* n){//создаёт массивы, с которыми мы работаем
    char s[256];// строка
    static char* s1;// первая часть
    static char* s2;// втроая
    
    while(fgets(s, 256, f)){
        if(s[0]!='\n'){// пропускаем пустые строки
        split_strings(s, &s1, &s2);
        //выделяем память для элемента
        m1[*n]=malloc ( 256 * sizeof( char*) );
        if(m1[*n])//если выделилось
            strcpy(m1[*n], s1);//копируем значение
        else{
            printf("Can't malloc for array");
            return;
        }

        m2[*n]=malloc ( 256 * sizeof( char*) );
        if(m2[*n])
            strcpy(m2[*n], s2);
        }
        else{
            printf("Can't malloc for array");
            return;
        }
        
        *n = *n+1;
    }
}

void print_arr(char** m1, size_t n){//выводит массив
    for(size_t i=0; i<n; i++){
        printf("%s\n", m1[i]);
    }
}



