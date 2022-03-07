#include<stdio.h>
#define n 30
void push(int x,int *top, int stack[]){
    *top=*top+1;
    stack[*top]=x;
}
int pop(int *top,int stack[]){
    int item;
    if(*top!=-1){
           item=stack[*top];
            *top=*top-1;
            
    }
    return item;
}
void dectobin(int x){
    int top=-1,stack[n],rem;
    while(x!=0){
        rem=x%2;
        push(rem,&top,stack);
        x=x/2;
    }
    while(top!=-1){
        printf("%d",pop(&top,stack));
    }
    printf("\n");
}
void dectohex(int x){
    int top=-1,stack[n],rem;
    while(x!=0){
        rem=x%16;
        push(rem,&top,stack);
        x=x/16;
    }
    while(top!=-1){
        int temp=pop(&top,stack);
        if(temp>=10&&temp<=15){
            if(temp==10){
                printf("A");
            }
            else if(temp==11){
                printf("B");
            }
            else if(temp==12){
                printf("C");
            }
            else if(temp==13){
                printf("D");
            }
            else if(temp==14){
                printf("E");
            }
            else if(temp==15){
                printf("F");
            }
        }
        else{
            printf("%d",temp);
        }
    }
}
int main(){
    printf("Enter the number to be converted: ");
    int x;
    scanf("%d",&x);
    printf("Binary form of: ");
    dectobin(x);
    printf("Hexadecimal form: ");
    dectohex(x);
}