#include<stdio.h>
#define size 30
int stack1[size],stack2[size];
int top1=-1,top2=-1;
int ctr=0;
void push1(int item){
    if(top1>=size-1){
        printf("Stack overflow..");
        
    }
    else{
        top1++;
        stack1[top1]=item;
    }
}

void push2(int item){
    if(top2>=size-1){
        printf("Stack overflow...");
    }
    else{
        top2++;
        stack2[top2]=item;
    }
}
int peek2(){
    if(top2!=-1){
        return stack2[top2];
    }
    else{
        printf("Stack empty");
    }
}
int peek1(){
    if(top1!=-1){
        return stack1[top1];
    }
    else{
        printf("Stack empty");
    }
}
int pop1(){
    if(top1==-1){
        printf("Stack empty...");
    }
    else{
        return stack1[top1];
        top1--;
    }
}


int pop2(){
    if(top2==-1){
        printf("Stack empty");
        
    }
    else{
        return stack2[top2];
        top2--;
    }
}
int minim(int stack2[]){
    int min=stack2[top2];
    int temp;
    int i;
    int k = top2;
    for(i=0;i<ctr;i++,k--){
        temp=stack2[k];
        if(temp<min){
            min=temp;
        }
    }
    return min;
    
}
int main(){
    
    int ch,flag=0;
   
    while(flag==0){
        printf("1.Push\n2.pop.\n3.Minimum.\nEnter the choice..");
         scanf("%d",&ch);
        switch(ch){
        case 1:{
            printf("Enter the element to be pushed..");
            int item;
            scanf("%d",&item);
            push1(item);
            push2(item);
            ctr++;
            break;
        }
        case 2:{
            printf("Enter the number of times popping to be done: ");
            int i,n;
            scanf("%d",&n);
            printf("Popped elements: ");
            for(i=0;i<n;i++){
                int temp=pop1();
                ctr--;
                pop2();
                printf("%d\t",temp);
                
            }
            
        }
        case 3:{
           int min=minim(stack2);
           printf("%d\n",min);
           flag=1;
            
            break;
            
        }
    }
    
    }
    return 0;
    
}
