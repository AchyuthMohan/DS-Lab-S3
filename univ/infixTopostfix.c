#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 20

int top=-1;
char stack[size];
void push(char ch){
    if(top==size-1){
        printf("Full..");
    }
    else{
        top++;
        stack[top]=(char)ch;
    }
}
char pop(){
    if(top!=-1){
        char item=stack[top];
        top--;
        return item;
    }
    // return '/0';
}
int precedence(char ch){
    if(ch=='*'||ch=='/'){
        return 2;
    }
    if(ch=='^'){
        return 3;
    }
    if(ch=='+'||ch=='-'){
        return 1;
    }
    
}
int isParen(char ch){
    if(ch=='{'||ch=='['||ch=='('||ch=='}'|ch==']'||ch==')'){
        return 1;
    }
    else{
        return 0;
    }
}
int isOperator(char ch){
    if(ch=='+'||ch=='*'||ch=='/'||ch=='^'||ch=='%'||ch=='-'){
        return 1;
    }
    else{
        return 0;
    }
}
void infixToPostfix(char exp[],int n){
    for(int i=0;i<n;i++){
        if(isOperator(exp[i])==0){
            printf("%c",exp[i]);
        }
        else{
            if(top==-1){
                push((char)exp[i]);

            }
            else{
                if(precedence(stack[top])>=exp[i]){
                    while(precedence(stack[top])>=exp[i]){
                        char item=pop();
                        printf("%c",item);
                    }
                    push(exp[i]);
                }
            }
        }
    }
}
int main(){
    char exp[30];
    printf("Enter the expression: ");
    gets(exp);
    int n=strlen(exp);
    infixToPostfix(exp,n);
    
}