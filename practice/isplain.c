#include<stdio.h>
#include<string.h>
#define size 30
int top=-1;
char stack[size];
void push(char ch){
    if(top==size-1){
        printf("The stack is full..");
    }
    else{
        top++;
        stack[top]=ch;
    }
}
char pop(){
    if(top==-1){
        printf("Empty..\n");
    }
    else{
        char item=stack[top];
        top=top-1;
        return item;
    }
}
int main(){
    printf("Enter the string: \n");
    char str[size];
    int state=0;
    gets(str);
    int n=strlen(str);
    for(int i=0;i<n;i++){
        push(str[i]);
    }
    for(int i=0;i<n;i++){
        if(str[i]!=pop()){
            state=1;
            break;
        }
    }
    if(state==0){
        printf("Palindrome");
    }
    else{
        printf("Not palindrome");
    }

}