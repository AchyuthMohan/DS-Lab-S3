#include<stdio.h>
#include<math.h>
struct poly{
    float coeff;
    int expo;
    
};

int main(){
    struct poly a[20];
    int n,i,x;
    printf("Enter the degree of the polynomial: ");
    scanf("%d",&n);
    printf("Enter the polynomial: ");
    for(i=0;i<=n;i++){
        printf("Enter the coefficient: ");
        scanf("%f",&a[i].coeff);
        printf("Enter the exponential: ");
        scanf("%d",&a[i].expo);
    }
    printf("Enter the x value: ");
    scanf("%d",&x);
    float sum=0;
    for(i=0;i<=n;i++){
        sum+=a[i].coeff*pow(x,a[i].expo);
    }
    printf("%f",sum);
}