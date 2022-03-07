#include<stdio.h>
#define size 30
struct poly{
    int coeff;
    int expo;
};
int l;
void pAdd(struct poly p1[],struct poly p2[],int n,int m){
    struct poly p3[size];
    int i=0,j=0,c=0;
    while(i<n&&j<m){
        if(p1[i].expo==p2[j].expo){
            p3[c].expo=p1[i].expo;
            p3[c].coeff=p1[i].coeff+p2[j].coeff;
            c++;
            i++;
            j++;

        }
        else if(p1[i].expo>p2[j].expo){
            p3[c].coeff=p1[i].coeff;
            p3[c].expo=p1[i].expo;
            c++;
            i++;
        }
        else if(p1[i].expo<p2[j].expo){
            p3[c].coeff=p2[j].coeff;
            p3[c].expo=p2[j].expo;
            c++;
            j++;
        }
    }
    l=c+1;
    for(i=0;i<l-1;i++){
        printf("Coefficient: %d  Exponent: %d\n",p3[i].coeff,p3[i].expo);
    }
}
int main(){
    int n,m;
    printf("Enter the number of terms in first polynomial: ");
    scanf("%d",&n);
    printf("Enter the number of terms in second polynomial: ");
    scanf("%d",&m);
    struct poly p1[size],p2[size];
    printf("Enter the values of first polynomial: ");
    for(int i=0;i<n;i++){
        int temp,temp1;
        printf("Enter the coefficient: ");
        scanf("%d",&temp);
        printf("Enter the exponent part: ");
        scanf("%d",&temp1);
        if(temp!=0){
            p1[i].coeff=temp;
            p1[i].expo=temp1;
        }
    }
    printf("Enter the values of second polynomial: ");
    for(int i=0;i<m;i++){
        int temp,temp1;
        printf("Enter the coefficient: ");
        scanf("%d",&temp);
        printf("Enter the exponent part: ");
        scanf("%d",&temp1);
        if(temp!=0){
            p2[i].coeff=temp;
            p2[i].expo=temp1;
        }
    }
    pAdd(p1,p2,n,m);
}