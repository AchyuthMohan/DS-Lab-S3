#include<stdio.h>
#define size 6
int queue[size],front=-1,rear=-1;
void insertFront(int x){
    if((front==0&&rear==size-1)||(front==rear+1)){
        printf("\nFull..");
    }
    else if(front==-1&&rear==-1){
        front =rear=0;
        queue[front]=x;
        
    }
    else if(front==0){
        front=size-1;
        queue[front]=x;
    }
    else{
        front--;
        queue[front]=x;
    }
}
void deleteFront(){
    if(front==-1&&rear==-1){
        printf("\nEmpty");
    }
    else if(front==size-1){
        int item=queue[front];
        front=0;
        printf("Deleted element: %d",item);
    }
    else if(front==rear){
        int item=queue[front];
        front=rear=-1;
         printf("Deleted element: %d",item);
    }
    else{
        int item=queue[front];
        front++;
        printf("Deleted element: %d",item);
    }
}
void insertRear(int x){
     if((front==0&&rear==size-1)||(front==rear+1)){
        printf("\nFull..");
    }
    else if(front==-1&&rear==-1){
        front =rear=0;
        queue[rear]=x;
        
    }
    else if(rear==size-1){
        rear=0;
        queue[rear]=x;
    }
    else{
        rear++;
        queue[rear]=x;
    }

}
void deleteRear(){
    if(front==-1&&rear==-1){
        printf("Empty..");
    }
    else if(front==rear){
        int item=queue[rear];
        front=rear=-1;
        printf("Deleted element: %d",item);
    }
    else if(rear==0){
        int item=queue[rear];
        rear=size-1;
        printf("Deleted element: %d",item);
    }
    else{
        int item=queue[rear];
        rear--;
        printf("Deleted element: %d",item);
    }
}
// void deleteRear(){
//      int item;
//     if(front==-1&&rear==-1){
//        printf("Empty...");

//     }
//     else if(front==rear){
//         item=queue[rear];
//         front=rear=-1;
//         printf("Data deleted: %d",item);
//     }
//     else if(rear==0){
//         item=queue[rear];
//         rear=size-1;
//         printf("Data deleted: %d",item);
//     }
//     else{
//         item=queue[rear];
//         rear--;
//         printf("Data deleted: %d",item);
//     }
// }
void display(){
    if(front==-1&&rear==-1){
        printf("Empty");
    }
    else{
        for(int i=front;i!=rear;i=(i+1)%size){
            printf("\nData: %d",queue[i]);
        }
    }
    printf("\nData: %d",queue[rear]);
    }
int main(){
    int state=0;
    while(state==0){
        printf("1. enque front 2. enqueue rear 3. delete front 4. delete rear 5. display 6.exit\n");
        int ch;
        scanf("%d",&ch);
        switch(ch){
            case 1:{
                printf("Enter the element to be added: ");
                int item;
                scanf("%d",&item);
                insertFront(item);
                break;
            }
            case 2:{
                printf("Enter the element to be added: ");
                int item;
                scanf("%d",&item);
                insertRear(item);
                break;
            }
            case 3:{
                deleteFront();
                break;
            }
            case 4:{
                deleteRear();
                break;
            }
            case 5:{
                display();
                break;
            }
            case 6:{
                state=1;
                break;
            }
        }
    }
}