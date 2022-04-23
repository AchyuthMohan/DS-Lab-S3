#include<stdio.h>
int a[30],n;
void merge(int a[],int lb,int mid,int ub){
    int i=lb;
    int j=mid+1;
    int k=lb;
    int b[40];
    while(i<=mid&&j<=ub){
        if(a[i]<=a[j]){
            b[k]=a[i];
            i++;
            k++;
        }
        else{
            b[k]=a[j];
            j++;
            k++;

        }
    }
    if(i>mid){
        while(j<=ub){
            b[k]=a[j];
            j++;
            k++;
        }
    }
    else{
        while(i<=mid){
            b[k]=a[i];
            i++;
            k++;
        }
    }
    for(k=lb;k<=ub;k++){
        a[k]=b[k];
    }
}
void mergeSort(int a[],int lb,int ub){
    if(lb<ub){
        int mid=(lb+ub)/2;
        mergeSort(a,lb,mid);
        mergeSort(a,mid+1,ub);
        merge(a,lb,mid,ub);
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
    mergeSort(a,0,n-1);
    printf("Sorted array: \n");
    for(int i=0;i<n;i++){
        printf("  %d",a[i]);
    }

}