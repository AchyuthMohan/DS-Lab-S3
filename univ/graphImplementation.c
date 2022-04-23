#define max 4
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct list{
    struct node *head;
};
struct list *adj_list[max]={0};
void addNode(int s, int d){
    
}
int main(){
    int i;
    for(i=0;i<max;i++){
        adj_list[i]=(struct list *)malloc(sizeof(struct list));
        adj_list[i]->head=NULL;
    }
    addNode(0,1);
    addNode(0,1);
    addNode(1,2);
    printList();

}