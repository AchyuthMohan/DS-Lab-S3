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
}
void insert(int x){
    struct node *newnode=create(x);
    if(head==NULL){
        head=tail=newnode;

    }
    else{
        newnode->next=head;
        tail->next=newnode;
        tail=newnode;
    }
}
int length(){
     struct node *temp;
    temp=head;
    int i=0;
    while(temp!=NULL){
        i++;
        temp=temp->next;
    }
    return i;
}
void delete(int pos){
    struct node *temp;
     if(pos>length()||pos<=0){
       printf("Invalid..");
   }
   if(pos==1){
    temp=head;
    head=head->next;
    tail->next=head;
    head->prev=tail;
    printf("Deleted item : %d\n",temp->data);
    free(temp);

   }
   else if(pos==length()){
       temp=tail;
       tail=tail->prev;
       tail->next=temp->next;
       head->prev=tail;
       printf("Deleted item : %d\n",temp->data);
       free(temp);
   }
   else{
       int i=0;
       temp=head;
       while(i<pos-1){
           i++;
           temp=temp->next;
       }
       temp->next->prev=temp->prev;
       temp->prev->next=temp->next;
       printf("Deleted elemet: %d\n",temp->data);
       free(temp);
   }
    
}
void display(){
    
    if(head==NULL){
        printf("Empty list..\n");
    }
    else{
        struct node *temp;
        temp=head;
        while(temp->next!=head){
            printf("Data: %d\n",temp->data);
            temp=temp->next;
        }
    }
}
int main(){
     int state=0;
    while (state==0){
        printf("1. add  2. delete 3.display 4. exit\n");
        int ch;
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:{
            printf("Enetr the element to be inserted: \n");
            int x;
            scanf("%d",&x);
            insert(x);
            break;
        }
        case 2:{
            printf("Enter the position from where deletion can be performed: ");
            int pos;
            scanf("%d",&pos);
            delete(pos);
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