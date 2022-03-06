#include<stdio.h>
#include<stdlib.h>
#define n 7
int queue[n];
int front=-1,rear=-1;
void enqueue(int x){
    if(front==(rear+1)%n){
        printf("\nFulll");
    }
    else if(front==-1&&rear==-1){
        front=rear=0;
        queue[rear]=x;
    }
    else{
        rear=(rear+1)%n;
        queue[rear]=x;
    }
}
void dequeue(){
    if(front==-1&&rear==-1){
        printf("\nEmpty!!");

    }
    else if(front==rear){
        printf("\nDeleted: %d",queue[front]);
        front=rear=-1;
    }
    else{
         printf("\nDeleted: %d",queue[front]);
         front++;
    }
}
void peek(){
    if(front==-1){
        printf("\nEmpty!!");
    }
    else{
        printf("\nfront element: %d",queue[front]);
    }
}
void display(){
    if(front==-1){
        printf("\nEmpty");
    }
    else{
        int i=front;
        for(;i<=rear;i++){
            printf("\nData: %d",queue[i]);
        }
    }
}
int main(){
    int state=0;
    while(state==0){
        printf("\n1.Enqueue 2.Dequeue 3.peek 4.display 5.exit");
        int ch;
        scanf("%d",&ch);
        switch(ch){
            case 1:{
                printf("\nEnter the element to be inserted: ");
                int x;
                scanf("%d",&x);
                enqueue(x);
                break;
            }
            case 2:{
                dequeue();
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