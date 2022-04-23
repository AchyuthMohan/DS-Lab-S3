#include<stdio.h>
void insertionSort(int a[],int n){
    for(int i=1;i<n;i++){
        int temp=a[i];
        int j=i-1;
        while(j>=0&&temp<=a[j]){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
}
int a[30],n;
int main(){
    printf("Enter the size: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Original array: \n");
    for(int i=0;i<n;i++){
        printf("  %d",a[i]);
    }
    insertionSort(a,n);
    printf("Sorted array: \n");
    for(int i=0;i<n;i++){
        printf("  %d",a[i]);
    }

}