#include<stdio.h>
#define n 50
int top1=-1,top2=-1;
int stack1[n],stack2[n];
void push1(int x){
    if(top1==n-1){
        printf("Full");
    }
    else{
        top1++;
        stack1[top1]=x;
    }
}
void push2(int x){
    if(top2==n-1){
        printf("Stack full");
    }
    else{
        top2++;
        stack2[top2]=x;
    }
}
int pop1(){
   int item=stack1[top1];
   top1--;
   return item;
}
int pop2(){
    int item=stack2[top2];
    top2--;
    return item;
}
int peek(){
    return stack1[top1];
}
void insert(int x){
    if(top1==-1){
        push1(x);
    }
    else{
        int topel=peek();
        if(x>topel){
            while(x>topel){
                int element =pop1();
                push2(element);
                topel=peek();
            }
            push1(x);
            while(top2!=-1){
                push1(pop2());
            }
        }
    }
}
void display(){
    if(top1==-1){
        printf("Empty");
    }
    else{
        int i=top1;
        while(i!=-1){
            printf("Data: %d\n",stack1[i]);
            i--;
        }
    }
}
int main(){
    int state=0;
    while(state==0){
        printf("1. push 2. pop 3. minimum 4.exit 5.display");
        int ch;
        scanf("%d",&ch);
        switch(ch){
            case 1:{
                printf("Enter the data to be inserted...");
                int item;
                scanf("%d",&item);
                insert(item);
                break;
            }
            case 2:{
                int item=pop1();
                printf("Popped data: %d",item);
                break;
            }
            case 3:{
                printf("Minimum element is: %d\n",stack1[top1]);
                break;
            }
            case 4:{
                state=1;
                break;
            }
            case 5:{
                display();
                break;
            }
        }
    }
}
