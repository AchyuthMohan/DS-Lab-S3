#include<stdio.h>
struct poly{
     int coeff;
     int expo;
};
int raiseto(int a,int b){
    int p=1;
    if(b==0){
        return 1;
    }
    else{
         for(int i=0;i<b;i++){
        p=p*a;
    }
    return p;

    }
   
}
void peval(struct poly a[],int n,int s){
    int res=0;
    for(int i=0;i<n-1;i++){
        int m=raiseto(s,a[i].expo);
        res+=a[i].coeff*m;
    }
    printf("Result: %d",res);
}
int main(){
    printf("Enter the number of terms: ");
    int n; 
    int i;
    struct poly a[30];
    scanf("%d",&n);
    int c=0;
    // int test=raiseto(5,2);
    // printf("%d",test);
    printf("Enter the terms: ");
    for(i=0;i<n;i++){
        printf("Enter the coefficient: ");
        int temp;
        scanf("%d",&temp);
        printf("Enter the exponent part: ");
        int temp2;
        scanf("%d",&temp2);
        if(temp!=0){
            a[c].coeff=temp;
            a[c].expo=temp2;
            c++;
        }
    }
    printf("Enter the alue for substitute:");
    int s;
    scanf("%d",&s);
    peval(a,c+1,s);

}