#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    char data;
    struct node *next;
    struct node *prev;
};
struct node *head=NULL,*tail=NULL;
struct node *create(char x){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=newnode->prev=NULL;
    return newnode;
}
void insert(char ch){
    struct node *newnode=create(ch);
    if(head==NULL){
        head=tail=newnode;
    }
    else{
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }
}
int length(){
    struct node *temp=head;
    int sum=0;
    while(temp!=NULL){
        sum++;
        temp=temp->next;
    }
    return sum;
}
void isPalin(){
    // struct node *i=head,*j=tail;
    int l=length();
    int mid=l/2;
    int i=1;
    struct node *start=head,*end=tail;
    int flag=0;
    while(i<=mid){
        if(start->data!=end->data){
            flag=1;
            break;
        }
        else{
            start=start->next;
            end=end->prev;
            i++;
        }
    }
    if(flag==0){
        printf("Palindrome..");
    }
    else{
        printf("Not Palindrome");
    }
}
int main(){
    printf("Enter the string: ");
    char str[30];
    gets(str);
    int n=strlen(str);
    for(int i=0;i<n;i++){
        insert(str[i]);
    }
    isPalin();

}