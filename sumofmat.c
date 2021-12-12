#include<stdio.h>
struct matrix{
    int row;
    int column;
    int value;
};
int main(){
    struct matrix a[30],b[30],res[30];
    int n,m,i,j,k,c=1;
    printf("Enter the number of rows: ");
    scanf("%d",&n);
    printf("Enter the number of columns: ");
    scanf("%d",&m);
    printf("Enter the first matrix: \n");
    a[0].row=n;
    a[0].column=m;
    int ctr=0;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("Enter the element: ");
            scanf("%d",&k);
            if(k!=0){
                a[c].row=i;
                a[c].column=j;
                a[c].value=k;
                ctr++;
                c++;
            }
        }
    }
    a[0].value=ctr;
    
    printf("Enter the second matrix: \n");
    c=1;
    b[0].row=n;
    b[0].column=m;
    ctr=0;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("Enter the element: ");
            scanf("%d",&k);
            if(k!=0){
                b[c].row=i;
                b[c].column=j;
                b[c].value=k;
                ctr++;
                c++;
            }
        }
    }
    b[0].value=ctr;
    printf("First matrix: \n");
    for(i=0;i<=a[0].value;i++){
        printf("Row: %d   Column: %d    Value: %d   \n",a[i].row,a[i].column,a[i].value);
    }
    printf("Second matrix: \n");
    for(i=0;i<=b[0].value;i++){
        printf("Row: %d   Column: %d    Value: %d   \n",b[i].row,b[i].column,b[i].value);
    }
    c=1;
    ctr=0;
   for(i=1;i<=a[0].value;i++){
       for(j=1;j<=b[0].value;j++){
           if(a[i].row==b[j].row&&a[i].column==b[j].column){
             res[c].row=a[i].row;
             res[c].column=a[i].column;
             res[c].value=a[i].value+b[j].value;
             c++;
             ctr++;
           }
           else if(a[i].row==b[j].row&&a[i].column!=b[j].column){
               res[c].row=a[i].row;
               if(a[i].column<b[j].column){
                   res[c].column=a[i].column;
                   res[c].value=a[i].value;
                   c++;
                   ctr++;
               }
               else{
                   res[c].column=b[j].column;
                   res[c].value=b[j].value;
                   c++;
                   ctr++;
               }
           }
           else if(a[i].row!=b[j].row&&a[i].column==b[j].column){
               res[c].column=b[j].column;
               if(a[i].row<b[j].row){
                   res[c].row=a[i].row;
                   res[c].value=a[i].value;
                   c++;
                   ctr++;
               }
               else{
                   res[c].row=b[j].row;
                   res[c].value=b[j].value;
                   c++;
                   ctr++;
               }
           }
           
       }
   } 
   res[0].value=ctr;
   printf("resultant matrix: \n");
    for(i=1;i<=res[0].value;i++){
        printf("Row: %d   Column: %d    Value: %d   \n",res[i].row,res[i].column,res[i].value);
    }
   
}