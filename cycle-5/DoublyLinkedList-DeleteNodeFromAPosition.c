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
int length(){
    temp=head;
    int i=0;
    while(temp!=NULL){
        i++;
        temp=temp->next;
    }
    return i;
}
void deleteFromPos(int pos){
    // temp=head;
    // printf("Hello");
    // printf("%d",pos);
   if(pos>length()||pos<=0){
       printf("Invalid..");
   }
   if(pos==1){
    temp=head;
    head=head->next;
    head->prev=NULL;
    printf("Deleted elemet: %d\n",temp->data);
    free(temp);

   }
   else if(pos==length()){
       temp=tail;
       tail=tail->prev;
       tail->next=NULL;
       printf("Deleted elemet: %d\n",temp->data);
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
    temp=head;
    if(temp==NULL){
        printf("Empty..\n");
    }
    else{
        while (temp!=NULL)
        {
           printf("Data: %d\n",temp->data);
           temp=temp->next;
        }
        
    }
}
int main(){
    int state=0;
    while(state==0){
        printf("1. add 2. deletepos 3. display 4. exit");
        int ch;
        scanf("%d",&ch);
        switch(ch){
            case 1:{
                printf("Enter the element to be added: \n");
                int x;
                scanf("%d",&x);
                add(x);
                break;
            }
            case 2:{
                printf("Enter the pos to be deleted: \n");
                int pos;
                scanf("%d",&pos);
                deleteFromPos(pos);
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