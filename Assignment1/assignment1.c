#include<stdio.h>


int main(){

        char a[1000];
        char b[1000];
        char str[1000];
        FILE *p1 = fopen("input1.c","w");
        FILE *p2 = fopen("output.txt" , "w");

        while (1) {
            gets(str);
            if (strcmp(str, "stop") == 0)
                  break;
            strcat(str, "\n");
            fputs(str, p1);
        }
        fclose(p1);
        p1 = fopen("input1.c","r");

        char ch;
        int pos = 0;
        if(p1 == NULL){
            printf("File doesn't exist\n");
        }else{
            while(!feof(p1)){
              ch = fgetc(p1) ;
              a[pos] = ch;
              pos++;
            }
            a[pos] = '\0';
            fclose(p1);
        }

         for(int i = 0 ; i < strlen(a) ; ++i){
               if(a[i] == '\n'){
                  continue;
               }
               else if(a[i] == '/' && a[i+1] == '/'){
                    ++i;
                    while(a[++i] != '\n'){
                        continue;
                    }
               }
               else if(a[i] == '/' && a[i+1] == '*'){
                ++i;
                while(a[++i] !='/'){
                        continue;
                }
               }
               else{
                 fputc(a[i] , p2);
                }
        }

        fclose(p2);

    p2 = fopen("output.txt" , "r");

    if(p2 == NULL){
        printf("File doesn't exist\n");
     }else{
        while(!feof(p2)){
            ch = fgetc(p2);
            printf("%c" , ch);
        }

       fclose(p2);
    }


   return 0;
}



