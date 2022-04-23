#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;

};
struct node *create(int x){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->right=newnode->left=NULL;
    return newnode;
}
void insert(struct node *root,struct node *newnode){
    if(root->data<newnode->data){
        if(root->right==NULL){
            root->right=newnode;
        }
        else{
            insert(root->right,newnode);
        }
    }
    if(root->data>newnode->data){
        if(root->left==NULL){
            root->left=newnode;
        }
        else{
            insert(root->left,newnode);
        }
    }
}
struct node *inOrderPredecessor(struct node *root){
    root=root->left;
    while(root->right!=NULL){
        root=root->right;
    }
    return root;
}
struct node *delete(struct node *root, int value){
    struct node *ipre;
    if(root==NULL){
        return NULL;
    }
    if(root->left==NULL&&root->right==NULL){
        free(root);
    }
    else{
        if(root->data>value){
            delete(root->left,value);
        }
        else if(root->data<value){
            delete(root->right,value);
        }
        else{
            ipre=inOrderPredecessor(root);
            root->data=ipre->data;
            delete(root->left, ipre->data);
        }
    }
}

void inorder(struct node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("\nData: %d",root->data);
    inorder(root->right);
}

int main(){
    struct node *root=NULL;
    int state=0;
    while(state==0){
        printf("1. insert 2. delete 3. inorder 4. exit");
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
                break;
            }
            case 2:{
                printf("Enter the value to be deleted: ");
                int item;
                scanf("%d",&item);
                delete(root,item);
                break;

            }
            case 3:{
                inorder(root);
                break;
            }
            case 4:{
                state=1;
                break;
            }
        }
    }
}