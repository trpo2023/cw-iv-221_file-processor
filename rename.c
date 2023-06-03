#include <stdio.h>
//int ren( int res[i], int newname[i]){
int main (void)
{    
   printf ("Переименование каталога: ");
   // Переименование каталога
   if (-1 == rename ("pp", "ppppp")){
      printf ("Ошибка\n");
   }   
   else{ 
      printf ("Выполнено\n");
   } 
   return 0;
}