#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *right;
    struct node *left;
};
struct node *create(int x){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->left=newnode->right=NULL;
    return newnode;
}
void insert(struct node *root,struct node *newnode){
    if(root->data>newnode->data){
        if(root->left!=NULL){
            insert(root->left,newnode);
        }
        else{
            root->left=newnode;
        }
    }
    if(root->data<newnode->data){
        if(root->right!=NULL){
            insert(root->right,newnode);
        }
        else{
            root->right=newnode;
        }
    }
}
int val=0;
void count(struct node *root){
    
    if(root==NULL){
        val+=1;
        return;
    }
    count(root->left);
    count(root->right);


}
int main(){
    struct node *root=NULL;
    int state=0;
    while(state==0){
        printf("1. insert.  2. count 3. exit ");
        int ch;
        scanf("%d",&ch);
        switch(ch){
            case 1:{
                printf("Enter the data to be inserted: ");
                int item;
                scanf("%d",&item);
                struct node *newnode=create(item);
                if(root==NULL){
                    root=newnode;
                }
                else{
                    insert(root,newnode);
                }
            }
            break;
            case 2:{
                count(root);
                printf("No of leaves= %d",val);
                break;
            }
            case 3:{
                state=1;
                break;
            }
        }
    }

}