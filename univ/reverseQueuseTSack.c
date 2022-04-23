#include<stdio.h>
#include<stdlib.h>
#define size 6
int queue[size],stack[size],top=-1,front=-1,rear=-1;
void push(int item){
    if(top!=size-1){
        top++;
        stack[top]=item;
    }
}
int pop(){
    if(top!=-1){
        int item=stack[top];
        top--;
        return item;
    }
}
void enqueue(int x){
    if(rear==size-1){
        printf("Queue full..");
    }
    else if(front==-1&&rear==-1){
        front=rear=0;
        queue[rear]=x;
    }
    else{
        rear++;
        queue[rear]=x;
    }
}
int dequeue(){
    if(front==-1&&rear==-1){
        printf("Empty...");
    }
    else if(front==rear){
        int x=queue[front];
        front=rear=-1;
        return x;
    }
    else{
        int x=queue[front];
        front++;
        return x;

    }
}
void reverse(){
    int i;
    while(front!=-1){
        int x=dequeue();
        push(x);
    }
    while(top!=-1){
        int x=pop();
        enqueue(x);
    }

}
void display(){
    if(front==-1&&rear==-1){
        printf("Empty..");
    }
    else{
        for(int i=front;i<=rear;i++){
            printf("\nData: %d",queue[i]);
        }
    }
}
int main(){
    printf("Enter the number of data to be inserted: ");
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the element to be inserted: ");
        int x;
        scanf("%d",&x);
        enqueue(x);
    }
        printf("Initial: ");

        display();
        printf("reversed: ");
        reverse();
        display();
    


}
