#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *temp, *head=NULL,*newnode;

struct node *create(int item){
   struct node *newNode=(struct node*) malloc(sizeof(struct node ));
    newNode->data=item;
    newNode->next=NULL;
    return newNode;
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
    
    if(head==NULL){
        printf("Empty");
    }
    else{
        temp=head;
        while(temp!=NULL){
            printf("Data: %d\n",temp->data);
            temp=temp->next;
        }
    }
}
void delete(int item){
    struct node *del;
    if(item==head->data){
        temp=head->next;
        del=head;
        head=temp;
        free(del);
    }
    else{
        struct node *del = NULL;
        temp=head;

        if(head->data ==item)
        {
            del = head;
            head = head->next;
            free(del);
            printf("\nElement Deleted! \n");
        }
        else
        {
            while(temp != NULL)
            {
                if(temp->next!=NULL && temp->next->data == item)
                {
                    del = temp->next;
                    temp->next = temp->next->next;
                    free(del); 
                    printf("\nElement Deleted! \n");
                    break;
                }
                temp = temp->next;
            }
        }
        if(del == NULL)
            printf("\nElement not found! \n");
    }
}
int main(){
    add(1);
    add(2);
    add(3);

    display();
    delete(2);
    display();
}