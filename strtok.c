#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
int main(void){

//char ras[]={'.txt', '.png'};
//char newname[]= {'txt1', 'png1'};
    char sep[10]=".";
    char *istr;
    char str[10]={___должны быть именя файлов___};

   
    printf ("Результат разбиения:\n");
    istr = strtok (str,sep);

    while (istr != NULL)
    {
       //printf ("%s\n",istr);
       istr = strtok (NULL,sep);
    }

    return 0;
}
