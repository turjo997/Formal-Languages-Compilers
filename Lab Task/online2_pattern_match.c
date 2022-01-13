/*     
         Question:
         
         
        c(I)*_dd_ 
        where I = any character a to z and A to Z. and d = any digit between 0 to 9

*/


#include<stdio.h>

int main(){

        char str[100];

        printf("Enter the string: \n");
        scanf("%s" , str);

        int n = strlen(str);
        int f = 0 , pos = 0;

        for(int i = 0; i<n ; ++i){
                if(str[0] == 'c'){
                    ++i;
                    if(isalpha(str[i]) && i<n){
                        ++i;
                        if(i<n){
                        for(; i<n && str[i] != '_' ; ++i){
                            if(isalpha(str[i])){
                                continue;
                            }else{
                              f = 1; break;
                            }
                        }
                        if(str[i] == '_' && i<n){
                        asterisk:
                                ++i;
                          if(isdigit(str[i]) && i<n){
                            ++i;
                            if(i<n){
                                  for(;i<n;++i){
                                    if(isdigit(str[i]))
                                        continue;
                                    else{
                                        f =1 ; break;
                                    }
                                  }
                            }
                          }
                          else{
                              f = 1;
                              break;
                            }

                        }
                        else{
                              f = 1;
                              break;
                            }
                        }
                        else{
                            f = 1; break;
                        }
                    }else if(str[i] == '_'){
                       goto asterisk;
                    }
                else{
                  f = 1;
                  break;
                }

                }else{
                  f = 1;
                  break;
                }
        }

        if(f == 1){
            printf("pattern does not follow\n");
        }else{
           printf("pattern follows\n");
        }

  return 0;
}
