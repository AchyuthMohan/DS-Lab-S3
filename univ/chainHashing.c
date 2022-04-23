#include<stdio.h>
#include<stdlib.h>
#define size 10
struct node{
    int data;
    struct node *next;

};
struct node *chain[size];
void init(){
    for(int i=0;i<size;i++){
        chain[i]=NULL;
    }
}
struct node *create(int x){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    return newnode;
    
}
void insert(int x){
    struct node *newnode=create(x);
    int key;
    key=x%size;
    if(chain[key]==NULL){
        chain[key]=newnode;
    }
    else{
        struct node *temp=chain[key];
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }
}
void print(){
    for(int i=0;i<size;i++){
        struct node *temp=chain[i];
        printf("\nElements in the %d array index: ",i);
        while(temp!=NULL){
            printf("%d\t",temp->data);
            temp=temp->next;
        }
    }
}
int main(){
    init();
    printf("Enter the number of data: ");
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("enter the element: ");
        int item;
        scanf("%d",&item);
        insert(item);
    }
    print();
   


}
