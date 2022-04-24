#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head=NULL,*tail=NULL;
struct node *create(int x){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
};
void insert(int x){
    struct node *newnode=create(x);
    if(head==NULL){
        head=tail=newnode;
    }
    else{
        tail->next=newnode;
        tail=newnode;
    }
}
void reversal(){
    struct node *currentnode=head,*nextnode=head,*prevnode=NULL;
    // struct node *initHead=head;
    if(head==NULL){
        printf("Empty...");
    }
    else{
        while(nextnode!=NULL){
            nextnode=nextnode->next;
            currentnode->next=currentnode->prev;
            currentnode->prev=nextnode;
            // prevnode=currentnode;
            currentnode=nextnode;
        }
        struct node *temp=head;
        head=tail;
        tail=temp;
    }
}
void display(){
    if(head==NULL){
        printf("Empty..");
    }
    else{
        struct node *temp=head;
        while(temp!=NULL){
            printf("\nData: %d",temp->data);
            temp=temp->next;
        }
    }
}
int main(){
    int state=0;
    while(state==0){
        printf("1. add 2.reverse 3.display 4.exit: \n");
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
                reversal();
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
