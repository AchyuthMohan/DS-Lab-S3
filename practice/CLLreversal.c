#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;

};
struct node *head=NULL,*tail=NULL;
struct node *create(int x){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    return newnode;
}
void insert(int x){
    struct node *newnode=create(x);
    if(head==NULL){
        head=tail=newnode;
        tail->next=head;
    }
    else{
        newnode->next=tail->next;
        tail->next=newnode;
        tail=newnode;
    }
}
void display(){
    struct node *temp=head;
    if(head==NULL){
        printf("Empty...");
    }
    else{
        do{
            printf("Data: %d\n",temp->data);
            temp=temp->next;
        }while(temp!=head);
        
    }
}
void reverse(){
    struct node *current,*prev,*nextnode;
    current=tail->next;
    nextnode=current->next;
    if(tail==NULL){
        printf("Empty..\n");
    }
    else{
        while(current!=NULL){
            prev=current;
            current=nextnode;
            nextnode=current->next;
            current->next=prev;
        }
        nextnode->next=tail;
        tail=nextnode;
    }
}
int main(){
    int state=0;
    while(state==0){
        printf("1. Insert 2.Reverse 3.Display 4.exit");
        int ch;
        scanf("%d",&ch);
        switch(ch){
            case 1:{
                printf("Enter the element to be inserted: ");
                int item;
                scanf("%d",&item);
                insert(item);
                break;
            }
            case 2:{
                 reverse();
                 display();
                break;
            }
            case 3:{
                display();
                break;
            }
            case 4:{
                state=1;
                break;
            }
           
        }
    }
}
