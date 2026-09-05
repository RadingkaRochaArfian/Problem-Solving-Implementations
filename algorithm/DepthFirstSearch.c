#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp_desc(const void *a,const void*b){
    return (*(int*)b-*(int*)a);
}
int cmp_asc(const void *a,const void *b){
    return(*(int*)a-*(int*)b);
}
void initFindNonIncreasing(int row,int col,int graph1[col][row]){
    memset(graph1,0,sizeof(int)*row*col);
    graph1[1][0]=4;
    graph1[4][0]=1;
    graph1[4][0]=7;
    graph1[7][0]=4;
    graph1[2][0]=5;
    graph1[5][0]=2;
    graph1[5][0]=8;
    graph1[3][0]=6;
    graph1[6][0]=3;
    graph1[6][0]=9;
}
void dfs1(int n,int graph1[n+1][n+1]){//nonIncreasingByGraph
    int arr[]={0,4,2,1,9,3,5,6,7,8};
    int visited[n+1];
    int ans[n+1];
    memset(visited, 0, sizeof(visited));
    for(int i=1;i<=n;i++){
        if(visited[i])continue;
        int stack[n+1];
        int top=-1;
        stack[++top]=i;
        visited[i]=1;
        int cnt=0;
        int pos[n+1];
        int val[n+1];
        while(top>=0){
            int num=stack[top--];
            pos[cnt]=num;
            val[cnt]=arr[num];
            cnt++;
            for(int j=0;j<=n;j++){
                int adj=graph1[num][j];
                if(adj==0)continue;
                if(!visited[adj]){
                    visited[adj]=1;
                    stack[++top]=adj;
                } 
            }
        }
        qsort(pos,cnt,sizeof(int),cmp_asc);
        qsort(val,cnt,sizeof(int),cmp_desc);
        for(int j=0;j<cnt;j++){
            ans[pos[j]]=val[j];
        }
    }
    for(int i=1;i<=n;i++){
        printf("%d ",ans[i]);
    }
    printf("\n");
}
int main(){
    int n=9;
    int graph1[n+1][n+1];
    initFindNonIncreasing(n+1,n+1,graph1);
    dfs1(9,graph1);
}