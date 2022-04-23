#include<stdio.h>
#define size 35
int l[size];
void init(){
    for(int i=0;i<size;i++){
        l[i]=-1;
    }
}
void insert(int x){
    int key=x%size;
    if(l[key]==-1){
        l[key]=x;
    }
    else{
        for(int i=1;i<size;i++){
            int loc=(key+i*i)%size;
            if(l[loc]==-1){
                l[key+i]=x;
            }
        }
    }
}
void printer(){
    for(int i=0;i<size;i++){
        printf("%d\t",l[i]);
    }
}
int main(){
    init();
    printf("Enter the number of elemets: ");
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the element: ");
        int x;
        scanf("%d",&x);
        insert(x);
    }
    printer();

}