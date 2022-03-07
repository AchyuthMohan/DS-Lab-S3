
#include<stdio.h>
#define size 50
#include<stdlib.h>
void push(int x,int *top,int stack_arr[]){
*top=*top+1;
stack_arr[*top]=x;
}
int pop(int *top,int stack_arr[]){
int x;
if(*top == -1)
{
printf("Stack Underflow\n");
exit(1);
}
else
{
x = stack_arr[*top];
*top=*top-1;
}
return x;
}
void dectobin(int num){
int top=-1,stack[size],rem;
while(num!=0){
rem=num%2;
push(rem,&top,stack);
num=num/2;
}
while(top!=-1){
printf("%d",pop(&top,stack));
}
printf("\n");
}
void dectohex(int num){
int top=-1,stack[size],rem;
while(num!=0){
rem=num%16;
push(rem,&top,stack);
num=num/16;
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
else{
printf("F");
}
}
else{
printf("%d",temp);
}
}
printf("\n");
}
int main(){
printf("enter the number: ");
int n;
scanf("%d",&n);
printf("binary: ");
dectobin(n);
printf("\n");
printf("Hex: ");
dectohex(n);
return 0;
}