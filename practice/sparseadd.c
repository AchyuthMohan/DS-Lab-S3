#include<stdio.h>
#define size 30
struct mat{
    int row;
    int col;
    int val;
};
int main(){
    int n,m,i,j,a,b;
    struct mat p[size],w[size];
    printf("Enter the number of rows: ");
    scanf("%d",&n);
    printf("Enter the number of columns: ");
    scanf("%d",&m);
    
    printf("Enter the elements: ");
    p[0].row=n;
    p[0].col=m;
    int ctr=0;
    int c=1;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            int temp;
            printf("Enter the element: ");
            scanf("%d",&temp);
            if(temp!=0){
                ctr++;
                p[c].row=i;
                p[c].col=j;
                p[c].val=temp;
                c++;
            }
        }
    }
    p[0].val=ctr;
    printf("Enter the number of rows: ");
    scanf("%d",&n);
    printf("Enter the number of columns: ");
    scanf("%d",&m);
    printf("Enter the elements: ");
    w[0].row=n;
    w[0].col=m;
    ctr=0;
    c=1;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            int temp;
            printf("Enter the element: ");
            scanf("%d",&temp);
            if(temp!=0){
                ctr++;
                p[c].row=i;
                p[c].col=j;
                p[c].val=temp;
                c++;
            }
        }
    }
    w[0].val=ctr;



    
   
    printf("Efficient representation: \n");
    for(i=0;i<=p[0].val;i++){
        printf("Row: %d   Column: %d    Value: %d  \n",p[i].row,p[i].col,p[i].val);
    }
     printf("Efficient representation: \n");
    for(i=0;i<=w[0].val;i++){
        printf("Row: %d   Column: %d    Value: %d  \n",p[i].row,p[i].col,p[i].val);
    }

}