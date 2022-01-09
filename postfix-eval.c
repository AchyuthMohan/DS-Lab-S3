#include<stdio.h>
#include<string.h>
#define N 50
int stack[N],top=-1;
void push(int x){
    if(top==N-1){
        printf("Stack full");
    }
    else{
        top++;
        stack[top]=x;
    }
}
int pop(){
    if(top==-1){
        printf("Something went wrong");
    }
    else{
        return stack[top];
        top--;
    }
}
int isopera(char ch){
    if(ch=='+'||ch=='-'||ch=='^'||ch=='/'||ch=='^'||ch=='%'){
        return 0;

    }
    else{
        return 1;
    }
}
int main(){
    printf("Enter the expression: ");
    char str[N];
    scanf("%s",str);
    int n=strlen(str);
    int i;
    for(i=0;i<n;i++){
        
        if(isopera(str[i])==0){
            int temp2=pop();
            int temp1=pop();
            if(str[i]=='+'){
                push(temp1+temp2);
            }
            else if(str[i]=='-'){
                push(temp1-temp2);
            }
            else if(str[i]=='/'){
                push(temp1/temp2);
            }
            else if(str[i]=='*'){
                push(temp1*temp2);
            }
            else if(str[i]=='^'){
                push(temp1^temp2);
            }
            else if(str[i]=='%'){
                push(temp1%temp2);
            }
        }
        else{
           push((int)(str[i]));
        }
    }
    printf("%d",stack[top]);

}