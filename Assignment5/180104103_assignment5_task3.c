#include<stdio.h>

char str[1000];

int f = 0 , i = 0;

void Exp(){

    if(i == strlen(str)){
        f = 1;
        return;
    }

    Term();
    if(f && str[i] == '+' || str[i] == '-'){
       i++;
       Term();
    }
}

void Term(){
    if(i == strlen(str)){
        f = 1;
        return;
    }

    Factor();
    if(f == 1 &&  (str[i] == '*' || str[i] == '/')){
         i++;
         Factor();
    }
}

void Factor(){

        if(i == strlen(str)){
            f = 1;
            return;
        }

       ID();
       if(f == 1){
        return;
       }
       Num();
       if(f == 1){
        return;
       }
     if(str[i] == '('){
       i++;
       f = 1;
     }
     if(f){
        Exp();
        f = 1;
     }
     if(f){
        if(str[i] == ')'){
            i++;
            f = 1;
            return;
        }else{
          f = 0;
          return;
        }
     }else{
       f = 0;
       return;
     }
}

void ID(){
    if(i == strlen(str)){
        f = 1;
        return;
    }
    if(str[i] == 'a' || str[i] == 'b' || str[i] == 'c' || str[i] == 'd' || str[i] == 'e'){
        i++;
        f = 1;
        return;
    }else{
       f = 0;
       return;
    }
}

void Num(){

    if(i == strlen(str)){
        f = 1;
        return;
    }
    if(str[i] >= '0' ||  str[i] <= '9'){

        i++;
        f = 1;
        return;
    }else{
      f = 0;
      return;
    }
}

void stat(){

    asgn_stat();

    dscn_stat();

    loop_stat();
}

void asgn_stat(){

    if(i == strlen(str)){
        f = 1;
        return;
    }

    ID();

    if(f == 1 && (str[i] == '=')){
        i++;
        f = 1;
    }

    expn();
}

void expn(){

    if(i == strlen(str)){
        f = 1;
        return;
    }

   Exp();
   extn();
}

void extn(){

   if(i == strlen(str)){
        f = 1;
        return;
    }
 if(str[i] == ')'){
    f = 1;
    return;
  }

  relop();
  Exp();
}

void relop(){
    if(i == strlen(str)){
        f = 1;
        return;
    }
    if((str[i] == '=' && str[i+1] == '=') ||
       (str[i] == '!' && str[i+1] == '=')  || (str[i] == '<' && str[i+1] == '=') ||
        (str[i] == '>' && str[i+1] == '=')){
        i+=2;
        f = 1;
        return;
      }
      else if(str[i] == '<' || str[i] == '>'){
        i++;
        f = 1;
        return;
      }
      else{
        f = 0;
        return;
      }
}

void dscn_stat(){

    if(i == strlen(str)){
        f = 1;
        return;
    }
   if(str[i] == 'i' && str[i+1] == 'f'){
    i += 2;
    f = 1;
   }
   if(f == 1){
    if(str[i] == '('){
        i++;
        f = 1;
       }
   }else{
     f = 0;
   }
   if(f == 1){
     expn();
   }
   if(f == 1){
    if(str[i] == ')'){
        i++;
        f = 1;
    }
   }
   if(f == 1){
     stat();
   }
    extn1();
}

void extn1(){

   if(i == strlen(str)){
        f = 1;
        return;
    }
   if(str[i] == 'e' && str[i+1] == 'l' && str[i+2] == 's' && str[i+3] == 'e'){
      i+=4;
      f = 1;
   }
   if(f){
    stat();
   }

}
void loop_stat(){
    if(i == strlen(str)){
        f = 1;
        return;
    }

    if(str[i] == 'w' && str[i+1] == 'h' && str[i+2] == 'i' && str[i+3] == 'l'
       && str[i+4] == 'e'){
        i+=5;
        f = 1;
    }
     if(f){
        if(str[i] == '('){
            f = 1;
        }
     }else{
      f = 0;
     }
     if(f){
        expn();
     }
     if(f == 1){
       if(str[i] == ')'){
        f = 1;
       }
     }
     if(f){
        stat();
     }
     if(str[i] == 'f' && str[i+1] == 'o' && str[i+2] == 'r'){
        i+=3;
        f = 1;
     }
     if(f){

    if(str[i] == '('){
              i++;
              f = 1;
            }
      }
        if(f){
                asgn_stat();
        }
        if(f){
            if(str[i] == ';'){
                i++;
                f = 1;
              }
            }
            if(f){
                expn();
            }
            if(str[i] == ';'){
                    i++;
                    f = 1;
                }
            if(f){
                asgn_stat();
            }
            if(f){
                if(str[i] == ')'){
                    i++;
                    f = 1;
                }
            }
            if(f){
                stat();
            }else{
              f = 0;
              return;
            }

}

int main(){

   gets(str);

   stat();

   if(f == 1 && i == strlen(str)){
      puts("string matched");
   }else{
     puts("string does not matched");
   }


   //printf("%d %d\n",i , f);

  return 0;
}

//while(a==b)if(a==c)c=2elsec=3
//if(a+b)c=5
//if(a==c)c=2elsec=3
//for(a=b;b<c;d=a)if(a==c)c=2
//if(a==b)c=2
//if(a+b)c=5
