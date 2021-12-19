#include<stdio.h>
#define size 100
int a[size],top=-1,min,count=0;
void push(int item){
    if(top>=size-1){
        printf("Stack overflow..");
        
    }
    else{
        top++;
        a[top]=item;
    }
}
int pop(){
    if(top>-1){
        return a[top];
        
    }
    else{
        printf("stack underflow...");
    }
}
int minimum(int a[]){
    min=a[top];
    int temp;
    int i;
    int k = top;
    for(i=0;i<count;i++,k--){
        temp=a[k];
        if(temp<min){
            min=temp;
        }
    }
    return min;
    
}

int main(){
    int limit,flag=0,ch,i,item;
    while(flag==0){
        printf("\n1.push\n2.pop\n3.minimum\n4.exit");
        scanf("%d",&ch);
        switch(ch){
            case 1:{
                printf("Number of elements to be pushed: ");
                int t;
                scanf("%d",&t);
                for(i=0;i<t;i++){
                    printf("Enter teh element to be pushed: ");
                    scanf("%d",&item);
                    push(item);
                    count++;
                    
                }
                break;
            }
            case 2:{
                printf("Enter the number of times popping to be done: ");
                int t;
                scanf("%d",&t);
                for(i=0;i<t;i++){
                    item=pop();
                    count--;
                    printf("Element popped: %d",item);
                }
                
            }
            case 3:{
                 minimum(a);
                printf("Minimum: %d",min);
                break;
                
                
            }
            case 4:{
                flag=1;
            }
        }
    }
}