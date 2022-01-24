#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *temp,*head=NULL,*newnode;
struct node *create(int item){
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=item;
    newnode->next=NULL;
    return newnode;
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
    temp=head;
    if(head==NULL){
        printf("Empty");
    }
    else{
        while(temp!=NULL){
            printf("Data : %d\n",temp->data);
            temp=temp->next;
        }
    }
}
int counter(){
    int ctr=0;
    temp=head;
    if(head==NULL){
        return 0;
    }
    else{
        while(temp!=NULL){
            ctr++;
            temp=temp->next;
        }
        return ctr;
    }
    return ctr;
}
void delete(int pos){
     if(pos<1)
    {
        printf("INVALID, Index should start from 1\n");
    }
    else if(pos == 1)
    {
        if(head == NULL)
        {
            printf("Sorry, List Empty, cannot delete position %d",pos);
        }
        else
        {
            struct node *del = head;
            head = head->next;
            free(del);
            printf("Element at position %d Deleted. \n",pos);
        }
    }
    else
    {
       
        int elemNum = 1;
        struct node *temp = head;

        while(temp!=NULL && elemNum<pos-1)
        {
            temp = temp->next;
            elemNum++;
        }
      
        if(temp==NULL){elemNum--;}
        else {;}

        if(temp == NULL || temp->next == NULL)
            printf("Sorry, There are only %d nodes in the list", elemNum);
        else
        {   
            struct node *del = temp->next;
            temp->next = temp->next->next;
            free(del);
            printf("Element Deleted at position %d. \n",pos);
        }
    }
    
}
int main(){
    int state=0,ch;
    while(state==0){
        printf("1. add 2. delete 3. display 4. exit.");
        scanf("%d",&ch);
        switch(ch){
            case 1:{
                int item;
                printf("Enter the element to be added: ");
                scanf("%d",&item);
                add(item);
                break;
            }
            case 2:{
                int pos;
                printf("Enter the position to be deleted: ");
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
