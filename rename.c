#include <stdio.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>

void find_ras(char** c){  
   *c=strtok(*c, ".");
   *c=strtok(NULL,".");
   
}

void make_new_name(char* newname, char* c, int n, char* nras){
   char num[3];
   
   strcat(newname,c);
   
   if(n/10 <1) strcat(newname, "00");
   else if(n/100 <1) strcat(newname, "0");
   
   sprintf(num, "%d", n);
   strcat(newname, num);
   strcat(newname,".");
   strcat(newname, nras);
   
}

void rename_files(char* ras, char* name, DIR* dir,  char* input){
   printf("-NEW RENAME CYCLE %s\n", ras);
   rewinddir(dir);
   struct dirent *f; 
   int n=1;

   while ((f = readdir(dir)) != NULL)
   {
      if(f->d_name[0]=='.')
         continue;
    
      char oldname[256];
      strcpy(oldname, input);
      strcat(oldname,f->d_name);

      
      char *nras=f->d_name;
      find_ras(&nras);

      if(strcmp(nras, ras)!=0)
         continue;

      
      char newname[256];
      strcpy(newname, input);
      make_new_name(newname, name, n, nras);
      
      
      rename_and_err(oldname, newname);
      n++;
   }
}

void rename_and_err(char* oldname, char* newname){
   int ret = rename(oldname, newname);
   if(ret!=0){
      printf("Cant rename file %s", oldname);
      fprintf(stderr, "Error: %d\n", errno);
      
   }
}
