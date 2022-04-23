#include<stdio.h>
#include<stdlib.h>
struct node{
    char data;
    struct node *prev;
    struct node *next;
};
struct node *head=NULL, *tail=NULL;
struct node *create(char ch){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=ch;
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}
void insert(char ch){
    struct node *newnode=create(ch);
    if(head==NULL&&tail==NULL){
        head=tail=newnode;
    }
    else{
        newnode->prev=tail;
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
int main(){
    printf("Enter the string: ");
    char str[30];
    gets(str);
    int i=0,n;
    while(str[i]!='\0'){
        i++;
    }
    n=i;
    for(i=0;i<n;i++){
        insert(str[i]);
    }
    struct node *temp=head;
    struct node *temp1=tail;
    int l=length();
    int mid=l/2;
    int flag=0;
    for(i=0;i<mid;i++){
        if(temp1->data!=temp->data){
            flag=1;
            break;

        }
        else if(temp->data==temp1->data){
            temp=temp->next;
            temp1=temp1->next;
        }
    }
if(flag==0){
    printf("palindrome");
}
else{
    printf("not palindrome..");
}
}