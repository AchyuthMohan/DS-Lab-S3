#include<stdio.h>
#include<string.h>
#define n 34
char stack[n];
int top=-1;
char postfix[n];

void push(char ch){
    if(top==n-1){
        printf("Full");

    }
    else{
        top++;
        stack[top]=ch;
    }
}
char pop(){
    // if(top==-1){
    //     printf("Empty");
    // }
    // else{
       char item=stack[top];
       top--;
       return item;
    // }
    
}
int isoperator(char ch){
    if(ch=='^'||ch=='*'||ch=='/'||ch=='+'||ch=='-'){
        return 1;
    }
    else{
        return 0;
    }
}
int precedence(char ch){
    if(ch=='^'){
        return 3;
    }
    else if(ch=='*'||ch=='/'){
        return 2;
    }
    else if(ch=='+'||ch=='-'){
        return 1;
    }
}

char peek(){
    if(top==-1){
        printf("Empty");
    }
    else{
        return stack[top];
    }
}
void infixToPostfix(char str[]){
    
}
int main(){
    char str[20];
    printf("Enter the infix expression: ");
    scanf("%s",&str);
    infixToPostfix(str);
    puts(postfix);
    
    // for(int i=0;i<strlen(str);i++){
    //     if(isoperator(str[i])==1){
    //         push(str[i]);
    //     }
    //     else{
    //         printf("%c",str[i]);
    //     }
    // }
    
}