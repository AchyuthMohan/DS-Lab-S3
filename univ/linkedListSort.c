#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head=NULL,*tail=NULL;
struct node *creat(int x){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    return newnode;
}
void insert(int x){
    struct node *newnode=creat(x);
    if(head==NULL){
        head=tail=newnode;
    }
    else{
        tail->next=newnode;
        tail=newnode;
    }

}
int length(){
    struct node *temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}
void Bsort(){
    if(head==NULL){
        printf("Empty..");
    }
    else{
        // int n=length();
        struct node *i=head,*j;
        while(i!=NULL){
            j=head;
            while(j!=NULL){
                if(i->data<j->data){
                    int temp=i->data;
                    i->data=j->data;
                    j->data=temp;
                }
                j=j->next;
            }
            i=i->next;
        }
    }
}
void display(){
    struct node *temp=head;
    while(temp!=NULL){
        printf("\nData: %d",temp->data);
        temp=temp->next;
    }
}
int main(){
    printf("Enter the number of items to be inserted: ");
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the data: ");
        int item;
        scanf("%d",&item);
        insert(item);
    }
    printf("Before: \n");
    display();
    printf("After: \n");
    Bsort();
    display();

}