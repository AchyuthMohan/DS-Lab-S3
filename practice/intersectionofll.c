#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head1,*head2,*tail1,*tail2,*tail3,*head3;
struct node *create(int x){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    return newnode;
}
void insert1(int x){
    struct node *newnode=create(x);
    if(head1==NULL){
        head1=tail1=newnode;

    }
    else{
        tail1->next=newnode;
        tail1=newnode;
    }
}
void insert2(int x){
    struct node *newnode=create(x);
    if(head2==NULL){
        head2=tail2=newnode;
    }
    else{
        tail2->next=newnode;
        tail2=newnode;
    }
}
void insert3(int x){
    struct node *newnode=create(x);
    if(head3==NULL){
        head3=tail3=newnode;
    }
    else{
        tail3->next=newnode;
        tail3=newnode;
    }
}
void intersection(){
    struct node *temp1,*temp2;
    temp1=head1;
    while(temp1!=NULL){
        temp2=head2;
        while(temp2!=NULL){
            if(temp1->data==temp2->data){
                insert3(temp1->data);
            }
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }
}
void display(struct node *h){
    struct node *temp=h;
    if(temp==NULL){
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
        printf("1. Insert first 2. Insert second 3. Intersection 4. display 1 5. display 2 6.exit");
        int ch;
        scanf("%d",&ch);
        switch(ch){
            case 1:{
                printf("Enter the element to be inserted: ");
                int item; 
                scanf("%d",&item);
                insert1(item);
                break;
            }
            case 2:{
                 printf("Enter the element to be inserted: ");
                int item; 
                scanf("%d",&item);
                insert2(item);
                break;
            }
            case 3:{
                intersection();
                display(head3);
                break;
            }
            case 4:{
                display(head1);
                break;
            }
            case 5:{
                display(head2);
                break;
            }
            case 6:{
                state=1;
                break;
            }
        }
    }
}
