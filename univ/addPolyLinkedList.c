#include<stdio.h>
#include<stdlib.h>
struct node{
    int exp;
    int coeff;
    struct node *next;
};
struct node *head1=NULL,*tail1=NULL,*head2=NULL,*tail2=NULL,*head3=NULL,*tail3=NULL;
struct node *create(int c,int e){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->coeff=c;
    newnode->exp=e;
    newnode->next=NULL;
    return newnode;
}
void insert1(int c,int e){
    struct node *newnode= create(c,e);
    if(head1==NULL){
        head1=tail1=newnode;
    }
    else{
        tail1->next=newnode;
        tail1=newnode;
    }

}
void insert2(int c,int e){
    struct node *newnode= create(c,e);
    if(head2==NULL){
        head2=tail2=newnode;
    }
    else{
        tail2->next=newnode;
        tail2=newnode;
    }

}
void insert3(int c,int e){
    struct node *newnode= create(c,e);
    if(head3==NULL){
        head3=tail3=newnode;
    }
    else{
        tail3->next=newnode;
        tail3=newnode;
    }

}

void add(){
    struct node *temp1=head1,*temp2=head2,*temp3=head3;
    int expo,coeff;
    while(temp1!=NULL&&temp2!=NULL){
        if(temp1->exp==temp2->exp){
            expo=temp1->exp;
            coeff=temp1->coeff+temp2->coeff;
            insert3(coeff,expo);
            temp1=temp1->next;
            temp2=temp2->next;

        }
        else if(temp1->exp>temp2->exp){
            expo=temp1->exp;
            coeff=temp1->coeff;
            insert3(coeff,expo);
            temp1=temp1->next;

        }
        else{

            expo=temp2->exp;
            coeff=temp2->coeff;
            insert3(coeff,expo);
            temp2=temp2->next;
        }
    }
    
}
void printer(struct node *h){
    struct node *temp=h;
    while(temp!=NULL){
        printf("Coefficient: %d     Exponent: %d\n",temp->coeff,temp->exp);
        temp=temp->next;
    }
}
int main(){
    int n,m;
    printf("Enter the first polynomial: ");
    printf("Enter the number of terms: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Coefficient: ");
        int coeff;
        scanf("%d",&coeff);
        int expo;
        printf("Exponent: ");
        scanf("%d",&expo);
        insert1(coeff,expo);
    }
    printf("Enter the second polynomial: \n");
    printf("Eter the number of terms: \n");
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        printf("Coefficient: ");
        int coeff;
        scanf("%d",&coeff);
        int expo;
        printf("Exponent: ");
        scanf("%d",&expo);
        insert2(coeff,expo);
    }
    add();
    printf("initial: \n");
    printer(head1);

    printf("\nSecondary: \n");
    printer(head2);
    printf("\nResult: \n");
    printer(head3);

}