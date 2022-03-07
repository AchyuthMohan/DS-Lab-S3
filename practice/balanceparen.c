#include<stdio.h>
#include<string.h>
#define size 40
int top=-1;
char stack[size];
void push(char ch){
   
    
        top++;
        stack[top]=ch;
  
}
char pop(){
    if(top==-1){
        printf("Empty");
    }
    else{
       char item=stack[top];
       top--;
       return item;
    } 
}
int isparen(char ch){
    if(ch=='{'||ch=='['||ch=='('||ch=='}'||ch==')'||ch==']'){
        return 1;
    }
    else{
        return 0;
    }
}
char peek(){
    return stack[top];
}
void isbalanced(char s[]){
    int m=strlen(s);
    for(int i=0;i<m;i++){
        if(isparen(s[i])==1){
            if(s[i]=='{'||s[i]=='['||s[i]=='('){
                push(s[i]);
            }
            else{
                if(s[i]=='}'){
                    if(peek()=='}'){
                        pop();
                        continue;
                    }
                    else{
                        printf("Unbalanced");
                        break;
                    }
                }
                else if(s[i]==']'){
                    if(peek()=='['){
                        pop();
                        continue;
                    }
                    else{
                        printf("Unbalanced expression..");
                        break;
                    }
                }
                else{
                    if(peek()=='('){
                        pop();
                        continue;
                    }
                    else{
                        printf("Unbalanced..");
                        break;
                    }

                }
            }
        }
    }
}
int main(){
    printf("Enter the string");
    char s[size];
    gets(s);
    isbalanced(s);
    if(top==-1){
        printf("balanced expression...");
    }

}