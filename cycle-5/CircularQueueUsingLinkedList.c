#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *front=NULL,*rear=NULL,*temp;
struct node *create(int x){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    return newnode;
}
void enqueue(int x){
    struct node *newnode=create(x);
    if(front==NULL&&rear==NULL){
        front=rear=newnode;
    }
    else{
        newnode->next=rear->next;
        rear->next=newnode;
        rear=newnode;
    }
}
void dequeue(){
    if(front==NULL){
        printf("\nEmpty..");

    }
    else if(front==rear){
        temp=front;
        printf("\nDeleted data: %d",temp->data);
        free(temp);
        front=rear=NULL;
    }
    else{
        temp=front;
        printf("\nDeleted data: %d",temp->data);
        front=front->next;
        free(temp);
    }
}
void display(){
    temp=front;
    if(front==NULL){
        printf("\nEmpty");
    }
    else{
        while(temp!=NULL){
        printf("\nData: %d",temp->data);
        temp=temp->next;
    }
    }
   
}
void peek(){
    if(front==NULL){
        printf("\nEmpty");
    }
    else{
        printf("\nFront data: %d",front->data);
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
