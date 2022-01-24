#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *temp, *head=NULL,*newnode;
struct node *create(int item){
   struct node *newNode=(struct node*) malloc(sizeof(struct node ));
    newNode->data=item;
    newNode->next=NULL;
    return newNode;
}
void add(int item){
    newnode=create(item);
    
    if(head==NULL){
        head=newnode;
        
    }
    else{
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;

    }
}
void display(){
    
    if(head==NULL){
        printf("Empty");
    }
    else{
        temp=head;
        while(temp!=NULL){
            printf("Data: %d\n",temp->data);
            temp=temp->next;
        }
    }
}
void reverse(){
    struct node *prevnode,*currentnode,*nextnode;
    prevnode=NULL;
    currentnode=nextnode=head;
    while(nextnode!=NULL){
        nextnode=nextnode->next;
        currentnode->next=prevnode;
        prevnode=currentnode;
        currentnode=nextnode;
    }
    head=prevnode;
}
int main(){
    int ch;
    int state=0;
    while(state==0){
        printf("1. add 2. reverse 3 display 4 exit");
        scanf("%d",&ch);
        switch(ch){
            case 1:{
                printf("enter the data to be added: ");
                int item;
                scanf("%d",&item);
                add(item);
                break;
            }
            case 2:{
                reverse();
                printf("Reversed...");
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