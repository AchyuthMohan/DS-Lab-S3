#include<stdio.h>
#include<string.h>
#define size 20
char stack[size];
int top=-1;
void push(char item){
    if(top>=size-1){
        printf("Overflow");
    }
    else{
        top++;
        stack[top]=item;
    }
}
char pop(){
    if(top==-1){
        printf("Underflow...");
    }
    else{
        return stack[top];
        top--;
    }
}
int main(){
    char str[size],str2[size];
    printf("Enter the string");
    scanf("%c",&str);
    
    int n=strlen(str);
    int i;
    for(i=0;i<n;i++){
        push(str[i]);
         }
    for(i=0;i<n;i++){
        str2[i]=pop();
    }
    if(strcmpi(str,str2)==0){
        printf("Palin");
    }
return 0;
}