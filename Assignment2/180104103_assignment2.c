#include<stdio.h>
#include<string.h>

int isSep(char ch){

    if(ch == '\'' || ch == ',' || ch == ';' || ch == ' '){
        return 1;
    }
    return 0;
}

int sepa(char *ch){
    if(strcmp("," , ch) == 0   || strcmp(";" ,ch) == 0 || strcmp(" " ,ch) == 0 || strcmp("\'" , ch) == 0){
        return 1;
    }
    return 0;
}
int isOP(char ch){
    if(ch == '+' || ch == '-' || ch =='*' || ch =='/' || ch =='>' || ch =='<' || ch == '!' || ch =='='){
        return 1;
    }
    return 0;
}
int isPAR(char ch){
    if(ch == '(' || ch == ')' || ch == '{' || ch == '}' || ch == '[' || ch == ']'){
        return 1;
    }
    return 0;
}
int par(char *ch){
    if(strcmp(ch , "(") == 0 || strcmp(ch , ")") == 0 || strcmp(ch , "{") == 0 || strcmp(ch , "}") == 0
       || strcmp(ch , "[") == 0 || strcmp(ch , "]") == 0 ){
        return 1;
       }
       return 0;

}
int iskey(char *ch){

    if(strcmp(ch , "int") == 0 || strcmp(ch , "double") == 0 || strcmp(ch , "float") == 0
       || strcmp(ch , "if") == 0 || strcmp(ch ,"else") == 0 || strcmp(ch , "char") == 0 ){
        return 1;
       }
       return 0;
}

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
int id(char *str){
    int n = strlen(str);
    int f = 0;

    for(int i = 0 ; i<n ; ++i){
        if (isAlpha(str[i]) || str[i] == '_'){
          ++i;
          if(i<n){
             for(; i<n ;++i){
              if(isAlpha(str[i]) || isDigit(str[i]) || str[i] == '_'){
                continue;
              }else{
                return 0;
              }
             }
          }

        }else{
          return 0;
        }
    }
    return 1;

}

int oper(char *str){
    if(strcmp(str , "+") == 0|| strcmp(str , "-") == 0 || strcmp(str , "*") == 0 || strcmp(str , "/") == 0
       ||strcmp(str , "==") == 0|| strcmp(str , ">=") == 0|| strcmp(str , "<=") == 0
       || strcmp(str , ">") == 0|| strcmp(str , "<") == 0 || strcmp(str , "!") == 0|| strcmp(str , "=") == 0){

         return 1;
       }
       return 0;
}
int isNum(char *lex)
{
    int i, l, s;
    i=0;
    if(isDigit(lex[i]))
    {
        s=1;
        i++;
    }
    else if(lex[i]=='.')
    {
        s=2;
        i++;
    }
    else s=0;
    l=strlen(lex);
    if(s==1)
        for(; i<l; i++)
        {
            if(isDigit(lex[i]))  s=1;
            else if(lex[i]=='.')
            {
                s=2;
                i++;
                break;
            }
            else
            {
                s=0;
                break;
            }
        }
    if(s==2)
        if(isDigit(lex[i]))
        {
            s=3;
            i++;
        }
        else
            s=0;
    if(s==3)
        for(; i<l; i++)
        {
            if(isDigit(lex[i]))  s=3;
            else
            {
                s=0;
                break;
            }
        }
    if(s==3) s=1;
    return s;
}

int main(){

        char a[1000];
        char b[1000];
        char str[1000];
        FILE *fp = fopen("input1.c","w");
        FILE *p2 = fopen("output.txt" , "w");

        while (1) {
            gets(str);
            if (strcmp(str, "end") == 0)
                  break;
            strcat(str, "\n");
            fputs(str, fp);
        }
        fclose(fp);
        fp = fopen("input1.c","r");

        char ch;
        int pos = 0;
        if(fp == NULL){
            printf("File doesn't exist\n");
        }else{
            while(!feof(fp)){
              ch = fgetc(fp) ;
              a[pos] = ch;
              pos++;
            }
            a[pos] = '\0';
            fclose(fp);
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

        pos = 0;
      if(p2 == NULL){
            printf("File doesn't exist\n");
        }else{
            while(!feof(p2)){
              ch = fgetc(p2) ;
              a[pos] = ch;
              ++pos;
            }
            a[pos] = '\0';
            fclose(p2);
        }

        puts(a);

        int n = strlen(a);
        int j = 0;
        for(int i = 0 ; i<n ; ++i){
             if (isSep(a[i]) == 1){
                if(a[i] == ' '){
                    b[j] = a[i];
                    ++j;
                }
                else if(a[i] == '\'' || a[i] == '\'' || a[i] == ';' || a[i] == ','){

                     if((a[i] == ';' && a[i+1] == ' ') || (a[i] == ',' && a[i+1] == ' ')){
                            b[j] = ' ';
                            ++j;
                            b[j] = a[i];
                            ++j;
                            b[j] = ' ';
                            ++j, ++i;
                     }
                     else{
                        b[j] = ' ';
                        ++j;
                        b[j] = a[i];
                        ++j;
                        b[j] = ' ';
                        ++j;
                     }
                }
             }
             else if(isOP(a[i]) == 1){

                    if((a[i] == '=' && a[i+1] == '=') ||(a[i] == '<' && a[i+1] == '=')
                           || (a[i] == '>' && a[i+1] == '=')){
                        b[j] = ' ';
                        ++j;
                        b[j] = a[i];
                        ++j;
                        b[j] = a[i+1];
                        ++j;
                        b[j] = ' ';
                        ++j,++i;
                    }
                    else{
                        b[j] = ' ';
                        ++j;
                        b[j] = a[i];
                        ++j;
                        b[j] = ' ';
                        ++j;
                    }
             }
             else if(isPAR(a[i]) == 1){
                    b[j] = ' ';
                    ++j;
                    b[j] = a[i];
                    ++j;
                    b[j] = ' ';
                    ++j;
             }
             else{
               b[j] = a[i];
               ++j;
             }
        }

        b[j] = '\0' ;

        int l = strlen(b);
        printf("%s\n" , b);

        printf("\n\n");

        j = 0;

        char new_ar[1000];

        for(int i = 0 ; i<l ;++i){
            if(b[i] == ' '){
             new_ar [j] = '\0';/*
            if(strlen(new_ar) == 0){
                j  =0;
                continue;
              }*/
            if(sepa(new_ar) == 1){
                printf("[sep %s]" , new_ar);
                j = 0;
             }
             else if(iskey(new_ar) == 1){
               printf("[kw %s]" , new_ar);
               j = 0;
             }
             else if(id(new_ar)== 1){
               printf("[id %s]" , new_ar);
               j = 0;
             }
             else if(oper(new_ar) == 1){
                 printf("[op %s]" , new_ar);
                 j = 0;
             }
              else if(par(new_ar) == 1){
                printf("[par %s]" , new_ar);
                j = 0;
             }
             else if(isNum(new_ar) == 1){
                 printf("[num %s]" , new_ar);
                 j = 0;
             }
             else{
                 printf("[unkn %s]" , new_ar);
                 j = 0;
             }
            }else{
              new_ar[j++] = b[i];
            }
        }

      return 0;
}
//char c; int x1, x_2; float y1, y2; x1=5; x_2= 10; y1=2.5+x1*45; y2=100.o5-x_2/3; if(y1<=y2) c='y'; else c='n';
