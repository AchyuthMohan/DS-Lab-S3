#include<stdio.h>
struct matrix{
    int row;
    int column;
    int value;
    
};
 struct matrix a[30],b[30],res[30];
void generate(struct matrix a[],int n,int m){
    int i,j,k,c=1,ctr=0;
    a[0].row=n;
    a[0].column=m;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
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
    a[0].value=ctr;
}
void printer(struct matrix a[]){
    int i;
    for(i=0;i<=a[0].value;i++){
        printf("Row: %d  Column: %d  Value: %d  \n",a[i].row,a[i].column,a[i].value);
    }
}
void sum(struct matrix a[],struct matrix b[]){
    int i=1,j=1,k=1;
    res[0].row=a[0].row;
    res[0].column=a[0].column;
    int size1=a[0].value;
    int size2=b[0].value;
    while(i<=size1&&j<=size2){
        if(a[i].row==b[j].row&&a[i].column==b[j].column){
            res[k].row=a[i].row;
            res[k].column=a[j].column;
            res[k].value=a[i].value+b[j].value;
            i++;
            j++;
        }
        else if(a[i].row==b[j].row){
            res[k].row=a[i].row;
            if(a[i].column<b[j].column){
                res[k].column=a[i].column;
                res[k].value=a[i].value;
                i++;
            }
            else{
                res[k].column=b[j].column;
                res[k].value=b[j].value;
                j++;
            }
        }
        else{
            if(a[i].row<b[j].row){
                res[k].row=a[i].row;
                res[k].column=a[i].column;
                res[k].value=a[i].value;
                i++;
                
            }
            else{
                res[k].row=b[j].row;
                res[k].column=b[j].column;
                res[k].value=b[j].value;
                j++;
                
            }
        }
        k++;
    }
    while(i<size1){
        res[k].row=a[i].row;
        res[k].column=a[i].column;
        res[k].value=a[i].value;
        i++;
        k++;
    }
    while(j<size2){
        res[k].row=b[j].row;
        res[k].column=b[j].column;
        res[k].value=b[j].value;
        j++;
        k++;
        
    }
    res[0].value=k-1;
}

int main(){
    int n,m,i;
   
    printf("Enter the no of rows and columns: ");
    scanf("%d%d",&n,&m);
    generate(a,n,m);
    generate(b,n,m);
    printf("First matrix: \n");
    printer(a);
    printf("Second matrix: \n");
    printer(b);
    sum(a,b);
    printf("Sum matrix: \n");
    printer(res);
    return 0;
    
}