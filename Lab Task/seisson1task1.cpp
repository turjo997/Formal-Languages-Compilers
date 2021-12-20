#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
char str[20];
int main(){

     FILE *p1;
     char ch;

     p1 = fopen("seisson1task11.cpp" , "r");

     string s = "";

     if(p1 == NULL){
        printf("File doesn't exist\n");
     }else{
         int pos = 0 ;
        while(!feof(p1)){
            ch = fgetc(p1);

            if(ch == ' ')
                continue;
            s+= ch;
        }
       fclose(p1);
    }

   for(int i = 0 ; i<s.size() ; i++){

       string ans = "";
        if(s[i] == '#' && s[i+1] =='i' && s[i+2] =='n' && s[i+3] =='c'
           && s[i+4] =='l'&& s[i+5] =='u' && s[i+6] =='d' && s[i+7] =='e'){
                 i = i + 8;
              if(s[i] == '<')
                ++i;

              while(s[i] !='>'){
                    ans+=s[i];
                    ++i;
              }
         cout<<ans<<endl;
        }


    }




   return 0;
}

