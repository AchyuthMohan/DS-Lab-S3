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
void display(){
    temp=head;
    if(head==NULL){
        printf("Empty..");
    }
    else{
        while(temp!=NULL){
        printf("Data: %d\n",temp->data);
        temp=temp->next;
    }
    }
}
int minimum(){
    int m=head->data;
    temp=head;
    while(temp!=NULL){
        if(temp->data<m){
            m=temp->data;
        }temp=temp->next;

    }
    return m;
}
void deletefrombeg(){
    temp=head;
    head=head->next;
    free(temp);

}
void deletefromend(){
    temp=tail;
    tail=tail->prev;
    tail->next=NULL;
    free(temp);
}
int length(){
    int i=0;
    temp=head;
    while(temp!=NULL){
        i++;
        temp=temp->next;
    }
    return i;
}


void delete(int m){
    temp=head;
    while(temp!=NULL){
        if(temp->data==m){
            if(temp==head){
                struct node *del=head;
                head=head->next;
                head->prev=NULL;
                free(del);
                temp=head;
            }
            else if(temp==tail){
                struct node *del=tail;
                tail=tail->prev;
                tail->next=NULL;
                free(del);
                temp=tail;

            }
            else{
                struct node *del=temp;
                struct node *target=temp->next;
                temp->next->prev=temp->prev;
                temp->prev->next=temp->next;
                free(del);
                temp=target;
            }
            
        }
        temp=temp->next;
        
    }
}
int main(){
    int state=0;
    while(state==0){
        printf("1. insert element 2. display 3. remove minimum element 4. exit ");
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
                display();
                break;
            }
            case 3:{
                int m=minimum();
                delete(m);
                break;
            }
            case 4:{
                state=1;
                break;
            }
        }
    }
}