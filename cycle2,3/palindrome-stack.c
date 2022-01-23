#include<stdio.h>
#define size 20
#include<string.h>
char stack[size];
int top=-1;
void push(char ch){
   top++;
   stack[top]=ch;
}
char pop(){
   if(top!=-1){
       return stack[top];
      }
    
}
int main(){
    char str[size],temp;
    int i,n,flag=0,ctr=1;
    printf("Enter the string..");
    scanf("%s",str);
    n=strlen(str);
   
    for(i=0;i<n;i++){
        
        push(str[i]);
    }
   
   
    for(i=0;i<n;i++){
        temp=pop();
        top--;
        if(temp!=str[i]){
            flag=1;
            break;
        }
    }
    if(flag==0){
        printf("Palindrome");
    }
    else{
        printf(" Not a palindrome");
    }
    
}