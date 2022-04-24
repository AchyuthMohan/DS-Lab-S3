#include<stdio.h>
#include<string.h>

#include<ctype.h>
#define size 30
char infix[20],postfix[20];
char stack[size];
int top=-1;
void push(char item){
	if(top!=size-1){
		top++;
		stack[top]=item;
	}
}
char pop(){
	if(top!=-1){
		char item=stack[top];
		top--;
		return item;
	}
}
int isoperator(char ch){
	if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^'){
		return 1;
	}
	else{
		return 0;
	}
}
int precedence(char ch){
	if(ch=='^'){
		return 3;

	}
	else if(ch=='/'||ch=='*'){
		return 2;
	}
	else if(ch=='+'||ch=='-'){
		return 1;
	}
	return 0;
}
void infixTopostfix(){
	int i=0,j=0;
	char item=infix[i];
	push('(');
	strcat(infix,")");
	while(item!='\0'){
		if(item=='('){
			push(item);
		}
		else if(isalpha(item)||isdigit(item)){
			postfix[j]=item;
			j++;

		}
		else if(isoperator(item)==1){
			char x=pop();
			while(precedence(x)>=precedence(item)){
				postfix[j]=x;
				j++;
				x=pop();

			}
			push(x);
			push(item);
		}
		else if(item==')'){
			char x=pop();
			while(x!='('){
				postfix[j]=x;
				j++;
				x=pop();
			}
		}
	i++;
	item=infix[i];

	}
	
}

int main(){
	printf("Enter the infix expression: ");
	gets(infix);
	int n=strlen(infix);
	infixTopostfix();
	// puts(postfix);
	for(int i=0;i<strlen(postfix);i++){
		printf("%c",postfix[i]);
	}


}