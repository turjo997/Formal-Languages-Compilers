/*
1. Write a program to recognize whether the entered string is a keyword or not.
2. Write a program to detect whether the entered string is an identifier or not based on the finite
automata described above.

*/

#include<stdio.h>
#include<string.h>
int isDigit(char ch){
    if(ch >= '0' && ch <= '9'){
        return 1;
    }
    return 0;
}
int isAlpha(char str){
    if((str >= 'a' && str <= 'z') || (str >= 'A' && str <= 'Z')){
        return 1;
    }
    return 0;
}

int iskey(char *ch){

    if(strcmp(ch , "int") == 0 || strcmp(ch , "double") == 0 || strcmp(ch , "float") == 0
       || strcmp(ch , "if") == 0 || strcmp(ch ,"else") == 0 || strcmp(ch , "char") == 0 || strcmp(ch , "include") == 0
       || strcmp(ch , "return") == 0 || strcmp(ch , "stdio.h") == 0 || strcmp(ch , "string.h") == 0 || strcmp(ch , "#") == 0
       || strcmp(ch , "main") == 0 || strcmp(ch , "void") == 0){
        return 1;
       }
       return 0;
}

int main(){

      char str[1000];
      char str1[1000];

      printf("Enter the string for checking keyword\n");
      gets(str1);
      printf("Enter the string for checking identifier\n");
      gets(str);
       int f = 0;

       int n = strlen(str);

   for(int i = 0 ; i< n ; ++i){
        if (isAlpha(str[i]) || str[i] == '_'){
          ++i;
          if(i<n){
             for(; i<n;  ++i){
              if(isAlpha(str[i]) || isDigit(str[i]) || str[i] == '_'){
                continue;
              }else{
                f = 1;break;
              }
             }
          }

        }else{
          f = 1; break;
        }
    }

    if(iskey(str1)){
        printf("String is a keyword\n");
    }else{
       printf("String is not a keyword\n");
    }
    if(f == 1){
        printf("Given pattern is not a identifier\n");
    }else{
        printf("Given pattern is a identifier\n");
    }



   return 0;
}
