#include<stdio.h>
#include<stdlib.h>
#define size 7
int top=-1;
int stack[size];
void push(int x){
    if(top==size-1){
        printf("Stack overflow!!");
    }
    else{
        top++;
        stack[top]=x;
    }
}
void peek(){
    printf("Peek elemenet: %d",stack[top]);
}
void display(){
    int i=top;
    while(i!=-1){
        printf("Data: %d\n",stack[i]);
        i--;
    }
}
int pop(){
    if(top==-1){
        printf("Empty");
    }
    else{
        top--;
        return stack[top];
    }
}
int main(){
    int state=0;
    while(state==0){
        printf("1. push 2. Pop 3. peek 4. display 5. Exit");
        int ch;
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:{
            printf("enter the number to be pushed: ");
            int x;
            scanf("%d",&x);
            push(x);
            break;
        }
        case 2:{
            int x=pop();
            printf("Popped element: %d",x);
            break;
        }
        case 3:{
            peek();
            break;
        }
        case 4:{
            display();
            break;
        }
        case 5:{
            state=1;
            break;
        }
        }
    }
}