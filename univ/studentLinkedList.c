#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    char name[20];
    int no;
    int mark;
    struct node *next;
};
struct node *head=NULL,*tail=NULL;
struct node *create(char str[],int n,int m){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->name=(char [])str;
    newnode->mark=m;
    newnode->no=n;
    newnode->next=NULL;
    return newnode;
}
void insert(char str[],int n,int m){
    struct node *newnode=create(str,n,m);
    if(head==NULL){
        head=tail=newnode;
    }
    else{
        tail->next=newnode;
        tail=newnode;
    }
}
void delete(int pos){
    struct node *temp=head;
    struct node *del;
    while(temp->no!=pos){
        del=temp;
        temp=temp->next;
    }
    del->next=temp->next;
    printf("data to be deleted: \n name: %s    no: %d   mark: %d\n",temp->name,temp->no,temp->mark);
    free(temp);
}
int main(){
    int state=0;
    while(state==0){
        printf("1. insert 2. delete 3. search 4. sort 5. exit");
        int ch;
        scanf("%d",&ch);
        switch(ch){
            case 1:{
                printf("Enter the name,number and mark: ");
                int n,m;
                char str[20];
                scanf("%s%d%d",str,&n,&m);
                insert(str,n,m);
                break;

            }
            case 2:{
                printf("Enter the no to be deleted: ");
                int num;
                scanf("%d",&num);
                delete(num);
                break;

            }
            case 3:{
                state=1;
                break;
            }
        }

    }
}