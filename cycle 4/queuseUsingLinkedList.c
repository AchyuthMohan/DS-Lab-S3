#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;

};
struct node *front=NULL,*rear=NULL,*temp;
struct node *create(int x){
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    return newnode;
}
void enque(int x){
    struct node *newnode=create(x);
    if(front==NULL){
        front=rear=newnode;
    }
    else{
        rear->next=newnode;
        rear=newnode;
    }
    
}
void deque(){
    if(front==NULL){
        printf("Underflow condition..\n");
    }
    else if(front==rear){
        temp=front;
        printf("deleted element: %d\n",temp->data);
        free(temp);
        front=rear=NULL;
    }
    else{
        temp=front;
        printf("deleted element: %d\n",temp->data);
        front=front->next;
        free(temp);
    }
}
void peek(){
    if(front==NULL){
        printf("Empty!!");

    }
    else{
        printf("front element: %d\n",front->data);
    }
}
void display(){
    if(front==NULL){
        printf("Empty!!\n");
    }
    else{
        temp=front;
        while(temp!=NULL){
            printf("data: %d\n",temp->data);
            temp=temp->next;
        }
    }
}
int main(){
    int state=0;
    while(state==0){
        printf("1. Enque 2. dequeue 3. peek 4. display 5. exit\n");
        int ch;
        scanf("%d",&ch);
        switch (ch)
        {
            case 1:{
                printf("Enter the element to be inserted:\n ");
                int x;
                scanf("%d",&x);
                enque(x);
                break;
            }
            case 2:{
                deque();
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