#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
    char data;
    struct node *next;
};
struct node *head1=NULL,*tail1=NULL,*temp,*head2=NULL,*tail2=NULL,*head3=NULL,*tail3=NULL;
struct node *create(char ch){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=ch;
    newnode->next=NULL;
    return newnode;

}
void insert1(char ch){
    struct node *newnode=create(ch);

    if(head1==NULL){
        head1=tail1=newnode;
    }
    else{
        tail1->next=newnode;
        tail1=newnode;
    }
}
void insert2(char ch){
    struct node *newnode=create(ch);

    if(head2==NULL){
        head2=tail2=newnode;
    }
    else{
        tail2->next=newnode;
        tail2=newnode;
    }
}
void reverse(){
    struct node *prev,*nextnode,*current;
    current=nextnode=head2;
    prev=NULL;
    while(current!=NULL){
        nextnode=nextnode->next;
        current->next=prev;
        prev=current;
        current=nextnode;
    }
    head2=prev;
}
void display(struct node *h){
    struct node *temp=h;
    if(h==NULL){
        printf("Empty..");
    }
    else{
        while(temp!=NULL){
            printf("%c ",temp->data);
            temp=temp->next;
        }
    }
}
void insert3(char ch){
    struct node *newnode=create(ch);

    if(head3==NULL){
        head3=tail3=newnode;
    }
    else{
        tail3->next=newnode;
        tail3=newnode;
    }
}
void linker(){
    struct node *temp=head1;
    while(temp!=NULL){
        insert3(temp->data);
        temp=temp->next;
    }
    temp=head2;
    while(temp!=NULL){
        insert3(temp->data);
        temp=temp->next;
    }

}
int main(){
    printf("Enter the string: ");
    char s[20];
    gets(s);
    int n=strlen(s);
    for(int i=0;i<n;i++){
        insert1(s[i]);
    }
    for(int i=0;i<n;i++){
        insert2(s[i]);
    }
    reverse();
    linker();
    printf("Resulting: \n");
    display(head3);

}
    