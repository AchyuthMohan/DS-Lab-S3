#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head=NULL,*tail=NULL,*temp;
struct node *create(int x){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}
void add(int x){
    struct node *newnode=create(x);
    if(head==NULL){
        head=tail=newnode;
    }
    else{
        newnode->prev=tail;
        tail->next=newnode;
        tail=newnode;
    }
}
int minimum(){
    temp=head;
    int min=head->data;
    while(temp!=NULL){
        if(temp->data<min){
            min=temp->data;
            temp=temp->next;
        }
        temp=temp->next;
    }
    return min;
}
void delete(){
    int m=minimum();
    if(head==NULL){
        printf("Empty\n");
    }
    else{
        // temp=head;
        
        if(head->data==m){
            temp=head;
            head=head->next;
            head->prev=NULL;
            printf("Deleted item: %d",temp->data);
            free(temp);
        }
        else if(tail->data==m){
            temp=tail;
            tail=tail->prev;
            tail->next=NULL;
            printf("Deleted item: %d",temp->data);
            free(temp);

        }
        temp=head->next;
        while(temp!=tail){
            if(temp->data==m){
                struct node *del=temp;
                
                del->next->prev=del->prev;
                
                del->prev->next=del->next;
                printf("Deleted item: %d",del->data);
                free(del);
                temp=temp->next;

            }
            temp=temp->next;

        }
        
    }
}
void display(){
    temp=head;
    if(head==NULL){
        printf("Empty..\n");
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
    while(state==0){
        printf("1. add element 2. delete smallest element 3. display 4. exit\n");
        int ch;
        scanf("%d",&ch);
        switch(ch){
            case 1:{
                printf("Enter the element to be inserted: ");
                int x;
                scanf("%d",&x);
                add(x);
                break;
            }
            case 2:{
                delete();
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