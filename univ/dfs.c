#include<stdio.h>
int a[30][30],n,reach[30];
void dfs(int v){
    int i;
    reach[v]=1;
    if(a[v][i]&&!reach[i]){
        printf("%d -> %d",v,i);
        dfs(i);
    }
}
int main(){
    int count=0;
    printf("Enter the no of vertices: ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        reach[i]=0;
        for(int j=1;j<=n;j++){
            a[i][j]=0;
        }
    }
    printf("Enter the adjacency matrix: ");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int item;
            scanf("%d",&item);
            a[i][j]=item;
        }
    }
    dfs(1);
    printf("\n");
    for(int i=1;i<=n;i++){
        if(reach[i]){
            count++;
        }
    }
    if(count==n){
        printf("graph is connected...");
    }
    else{
        printf("Grapsh is not connected..");
    }

}