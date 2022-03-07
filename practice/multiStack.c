#include<stdio.h>
#define size 5
int stack[size];
int top1=-1,top2=size;
void push1(int x){
    if(top1<top2-1){
        top1++;
        stack[top1]=x;
    }
    else{
        printf("Stack overflow:");
    }
}
void push2(int x){
    if(top1<top2-1){
        top2--;
        stack[top2]=x;
    }
    else{
        printf("Stack overflow..\n");
    }
}
int pop1(){
    if(top1==-1){
        printf("Stack underflow...\n");
    }
    else{
        int item=stack[top1];
        top1--;
        return item;
    }
}
int pop2(){
    if(top2==size){
        printf("Underflow...");
    }
    else{
        int item=stack[top2];
        top2++;
        return item;
    }
}
void display1(){
    if(top1==-1){
        printf("Empty stack 1");
    }
    else{
        int i=top1;
        while(i!=-1){
            printf("%d\n",stack[i]);
            i--;
        }
    }
}
void display2(){
    if(top2==size){
        printf("Empty stack 2.");
    }
    else{
        int i=top2;
        while(i!=size){
            printf("%d",stack[i]);
            i++;
        }
    }
}
int main(){
    int state=0;
    while(state==0){
        printf("1.push1 2. push2 3.display1 4.display2 5. exit\n ");
        int ch;
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:{
            printf("Enter the element to be inserted: ");
            int item;
            scanf("%d",&item);
            push1(item);
            break;
        }
        case 2:{
            printf("Enter the element to be inserted: ");
            int item;
            scanf("%d",&item);
            push2(item);
            break;
        }
        case 3:{
            display1();
            break;
        }
        case 4:{
            display2();
            break;
        }
        case 5:{
            state=1;
            break;
        }

    }
}//while
} //main