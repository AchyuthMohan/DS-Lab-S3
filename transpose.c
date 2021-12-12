#include<stdio.h>
struct matrix{
    int row;
    int column;
    int value;
};
int main(){
    struct matrix m1[300],m2[300];
    
    int a[30][30],n,i,j,m;
    printf("no of rows: ");
    scanf("%d",&n);
    printf("no of columns: ");
    scanf("%d",&m);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("Enter the element: ");
            scanf("%d",&a[i][j]);
        }
    }
    m1[0].row=n;
    m1[0].column=m;
    int c=1,ctr=0;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(a[i][j]!=0){
                m1[c].row=i;
                m1[c].column=j;
                m1[c].value=a[i][j];
                c++;
                ctr++;
            }
        }
    }
m1[0].value=ctr;
printf("Original matrix: \n");
for(i=0;i<=ctr;i++){
    printf("Row: %d     Column: %d       value: %d     \n",m1[i].row,m1[i].column,m1[i].value);
}
m2[0].row=m1[0].column;
m2[0].column=m1[0].row;
// for(i=0;i<=m1[0].column;i++){
//     for(j=1;j<=ctr;j++){
//       m2[j].row=m1[i].column;
//       m2[j].column=m1[i].row;
//       m2[i].value=m1[i].value;

//     }

// }
printf("transposed matrix: \n");
for(i=0;i<=ctr;i++){
    printf("Row: %d     Column: %d       value: %d     \n",m2[i].row,m2[i].column,m2[i].value);
}

}