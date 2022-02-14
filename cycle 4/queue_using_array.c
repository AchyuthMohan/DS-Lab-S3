#include<stdio.h>
#define size 5
int queue[size];
int front =-1;
int rear=-1;
void enque(int item){
    if(front==(rear+1)%size){
        printf("Full");
    }
    else if(front==-1&&rear==-1){
        front=rear=0;
        queue[rear]=item;
    }
    else{
        rear=(rear+1)%size;
        queue[rear]=item;
    }
}
void dequeue(){
   if(front==-1&&rear==-1){
       printf("Empty..");
   }
   else if(front==rear){
        printf("Deleted element: %d",queue[front]);
        front =rear=-1;
   }
   else{
       printf("deleted element: %d",queue[front]);
       front=(front+1)%size;
   }
}
void peek(){
   if(front==-1&&rear==-1){
      printf("empty");
   }
   else{
        printf("Peek: %d",queue[front]);
   }
}
void display(){
   int i=front;
    if(front==-1){
        printf("Emopty\n");
    }
    else{
        while(i!=rear){
        printf("%d\t",queue[i]);
        i=(i+1)%size;
    }
    printf("%d",queue[rear]);
    }
    
    
}
 int main(){
    int state=0;
    while(state==0){
        printf("1.Enque 2. deque 3. display 4. peek 5. exit");
        int ch;
        scanf("%d",&ch);
        switch(ch){
            case 1:{
                printf("Enter the elemnet to be enetered: ");
                int item;
                scanf("%d",&item);
                enque(item);
                break;
            }
            case 2:{
                dequeue();
                break;
            }
            case 3:{
                display();
                break;
            }
            case 4:{
                peek();
                break;
            }
            case 5:{
                state=1;
                break;
            }
        }
    }
 }
