#include<stdio.h>


int main(){

    char ch;

    FILE *p1 , *p2;

    p1 = fopen("input2.c" , "r");


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

       //   printf("Successfully written\n");
          fclose(p1);
    }

    for(int i = 0 ; i < strlen(str) ; ++i){


           if(str[i] == 'i' && str[i+1] == 'n' && str[i+2] == 't'
              && str[i+3] == ' '& str[i+4] == 'm'
              && str[i+5] == 'a' && str[i+6] == 'i' && str[i+7] == 'n' && str[i+8] == '('){

             i = i + 9;
              printf("The parameter is ");
             while(str[i] != ')' && strlen(str)){
                 printf("%c" , str[i]);
                 ++i;
             }
              printf("\n");
           }


            else if(str[i] == 'r' && str[i+1] == 'e' && str[i+2] == 't'
              && str[i+3] == 'u'& str[i+4] == 'r'
              && str[i+5] == 'n' && str[i+6] == ' '){

             i = i + 6;

              printf("The return value is" , str[i]);
             while(str[i] != ';' && strlen(str)){
                 printf("%c" , str[i]);
                 ++i;
             }
           }

    }




   return 0;
}





