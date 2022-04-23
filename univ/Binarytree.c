#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *create(){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data to be inserted or -1 if no data: ");
    int x;
    scanf("%d",&x);
    if(x==-1){
        return 0;
    }
    newnode->data=x;
    printf("Enter the left child data of %d: ",x);
    newnode->left=create();
    printf("Enter the right child data of %d: ",x);
    newnode->right=create();

    return newnode;

}
void inorder(struct node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("Data: %d",root->data);
    inorder(root->right);

}
void postorder(struct node *root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("Data: %d",root->data);
    
}
void preorder(struct node *root){
    if(root==NULL){
        return ;

    }
    printf("Data: %d",root->data);
    preorder(root->left);
    preorder(root->right);
}
int main(){
    int state=0;
    struct node *root=create();
    while(state==0){
        printf("1. inorder 2. postorder 3. preorder 4.exit");
        int ch;
        scanf("%d",&ch);
        switch(ch){
            case 1:{
                printf("inorder traversal is: \n");
                inorder(root);
                break;
            }
            case 2:{
                printf("postorder traversal: ");
                postorder(root);
                break;
            }
            case 3:{
                printf("Preorder traversal: ");
                preorder(root);
                break;
            }
            case 4:{
                state=1;
                break;
            }
        }
    }
        
}