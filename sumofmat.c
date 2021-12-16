#include<stdio.h>
struct matrix{
    int row;
    int column;
    int value;
};
struct matrix res[30];

int n,m,i,j,k;
void init(struct matrix a[]){
    int c=1,ctr=0;
    printf("Enter the elements: ");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&k);
            if(k!=0){
                a[c].row=i;
                a[c].column=j;
                a[c].value=k;
                c++;
                ctr++;
            }
        }
    }
    a[0].row=n;
    a[0].column=m;
    a[0].value=ctr;
}
void printmat(struct matrix a[],int n){
    for(i=0;i<=n;i++){
        printf("Row: %d  Column: %d  Value: %d\n",a[i].row,a[i].column,a[i].value);
    }
}
void summat(struct matrix a[],struct matrix b[]){
    res[0].row=n;
    res[0].column=m;
    int ctr=0;
    int i=1,j=1,k=1;
    while(i<=a[0].value&&j<=a[0].value){
        if(a[i].row==b[j].row&&a[i].column==b[j].column){
            res[k].row=a[i].row;
            res[k].column=a[i].column;
            res[k].value=a[i].value+b[j].value;
            i++;
            j++;
            k++;
            ctr++;
        }
        else if(a[i].row==b[j].row){
            res[k].row=a[i].row;
            if(a[i].column<b[j].column){
                res[k].column=a[i].column;
                res[k].value=a[i].value;
                i++;
                k++;
                ctr++;
                
            }
            else{
                res[k].column=b[j].column;
                res[k].value=b[j].value;
                j++;
                k++;
                ctr++;
            }
        }
        
    }
    res[0].value=ctr;
}
int main(){
    struct matrix a[30],b[30];
    printf("Enter the number of rows and columns of matrices: ");
    scanf("%d%d",&n,&m);
    init(a);
    init(b);
    printf("New representation of First: \n");
    printmat(a,a[0].value);
    printf("New representation of Second: \n");
    printmat(b,b[0].value);
    summat(a,b);
    printf("Result:\n");
    printmat(res,res[0].value);
    
}