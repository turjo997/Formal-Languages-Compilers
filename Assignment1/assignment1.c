#include<stdio.h>


int main(){

    char ch;

    FILE *p1 , *p2;

    p1 = fopen("input1.c" , "r");
    p2 = fopen("output.txt" , "w");

    char str[300];

    int pos = 0;

    if(p1 == NULL){
        printf("File doesn't exist\n");
    }else{

        while(!feof(p1)){
          ch = fgetc(p1) ;
          str[pos] = ch;
          pos++;
        }

        str[pos] = '\0';

          printf("Successfully written\n");
          fclose(p1);
    }

    for(int i = 0 ; i < strlen(str) ; ++i){

           if(str[i] == 'i' && str[i+1] == 'n' && str[i+2] == 't'
              && str[i+3] == ' ' && str[i+4] == 'm'){
             fputc(str[i] , p2);
             fputc(str[i+1] , p2);
             fputc(str[i+2] , p2);
             fputc(str[i+3] , p2);
             fputc(str[i+4] , p2);
             i = i + 4;
           }

           else if(str[i] == ' ' || str[i] == '\n'){
              continue;
           }
           else if(str[i] == '/' && str[i+1] == '/'){
                ++i;
                while(str[++i] != '\n'){
                    continue;
                }
           }
           else if(str[i] == '/' && str[i+1] == '*'){
            ++i;
            while(str[++i] !='/'){
                    continue;
            }
            ++i;
           }
           else{
             fputc(str[i] , p2);
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




