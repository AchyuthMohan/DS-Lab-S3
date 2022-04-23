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
struct node *delete(struct node *root, int value){
    struct node *ipre;
    if(root==NULL){
        return NULL;
    }
    if(root->right==NULL&&root->left==NULL){
        free(root);
    }
    else{
        if(value<root->data){
            delete(root->left,value);
        }
        else if(value>root->data){
            delete(root->right,value);
        }
        else{
            ipre= inOrderPredecessor(root);
            root->data = ipre->data;
            deleteNode(root->left, ipre->data);
        }
    }
}
struct node * inOrderPredecessor(struct node *root){
    root = root->left;
    while (root->right!=NULL)
    {
        root = root->right;
    }
    return root;
}
void inorder(struct node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("\nData: %d",root->data);
    inorder(root->right);

}
void preorder(struct node *root){
    if(root==NULL){
        return;
    }
    printf("\nData: %d",root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct node *root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("\nData: %d",root->data);
}

int main(){
    struct node*root=NULL;
    int state=0;
    while(state==0){
        printf("\n1. insert 2. inorder 3 preorder 4. postorder 5.delete 6. exit: \n");
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
                inorder(root);
                break;
            }
            case 3:{
                preorder(root);
                break;
            }
            case 4:{
                postorder(root);
                break;
            }
            case 5:{
                printf("Enter the element to be deleted: ");
                int item;
                scanf("%d",&item);
                delete(root,item);
                break;
            }
            case 6:{
                state=1;
                break;
            }
        }
    }
}