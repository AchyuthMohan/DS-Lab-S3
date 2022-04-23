#include<stdio.h>
int a[30],n;
int partition(int a[],int lb,int ub){
   int pivot=a[lb];
   int start=lb;
   int end=ub;
   int temp;
   while(start<end){
       while(a[start]<=pivot){
           start++;

       }
       while(a[end]>pivot){
           end--;
       }
       if(start<end){
           temp=a[start];
           a[start]=a[end];
           a[end]=temp;
       }
   }
   temp=a[end];
   a[end]=a[lb];
   a[lb]=temp;
   return end;
}
void quickSort(int a[],int lb,int ub){
    if(lb<ub){
        int loc=partition(a,lb,ub);
        quickSort(a,lb,loc-1);
        quickSort(a,loc+1,ub);
    }
}


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
    quickSort(a,0,n-1);
    printf("Sorted array: \n");
    for(int i=0;i<n;i++){
        printf("  %d",a[i]);
    }

}