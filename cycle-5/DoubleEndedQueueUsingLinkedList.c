#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;

};
struct node *head=NULL,*rear=NULL,*temp;
struct node *create(int x){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    return newnode;
}
void enqueuefront(int x){

    struct node *newnode=create(x);
    if(head==NULL&&rear==NULL){
        head=rear=newnode;
    }
    else{
        newnode->next=head;
        head=newnode;
    }  
}
void enqueuerear(int x){
    struct node *newnode=create(x);
    if(head==NULL&&rear==NULL){
        head=rear=newnode;
    }
    else{
        rear->next=newnode;
        rear=newnode;
    }  
}
void dequeuefront(){
    if(head==NULL){
        printf("Empty\n");
    }
    else{
        temp=head;
        head=head->next;
        printf("Deleted: %d\n",temp->data);
        free(temp);
    }
}
void dequeuerear(){
    if(rear==NULL){
        printf("Empty..\n");
    }
    else{
        temp=head;
        struct node *prev;
        while(temp->next!=NULL){
            prev=temp;
            temp=temp->next;
        }
        rear=prev;
        rear->next=NULL;
        printf("Deleted element: %d\n",temp->data);
        free(temp);

    }
}
void display(){
    temp=head;
    if(temp==NULL){
        printf("Empty!!\n");
    }
    else{
        while(temp!=NULL){
            printf("Data: %d\n",temp->data);
            temp=temp->next;
        }
    }
}
int main(){
    int state=0;
    while (state==0){
        printf("1. enqueue front 2. enqueue rear 3. dequeue front 4. dequeue rear 5. display 6. exit\n");
        int ch;
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:{
            printf("Enetr the element to be inserted: \n");
            int x;
            scanf("%d",&x);
            enqueuefront(x);
            break;
        }
        case 2:{
            printf("Enetr the element to be inserted: \n");
            int x;
            scanf("%d",&x);
            enqueuerear(x);
            break;
        }
        case 3:{
            dequeuefront();
            break;
        }
        case 4:{
            dequeuerear();
            break;
        }
        case 5:{
            display();
            break;
        }
        case 6:{
            state=1;
            break;
        }
        }
    }
    
}