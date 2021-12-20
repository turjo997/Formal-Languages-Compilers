#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
char str[20];
int main(){

     FILE *p1;
     char ch;

     p1 = fopen("seisson1task2.cpp" , "r");

     string s = "1:";

     if(p1 == NULL){
        printf("File doesn't exist\n");
     }else{
         int pos = 0 ;
        while(!feof(p1)){
            ch = fgetc(p1);
            s+= ch;
        }
       fclose(p1);
    }

    int l =2;
    for(int i = 0 ; i<s.size() ; ++i){

            cout<<s[i];
            if(s[i] == '\n'){
                cout<<l<<":";
                ++l;
            }

    }



   return 0;
}


