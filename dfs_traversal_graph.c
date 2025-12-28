#include <stdio.h>
int g[10][10],v[10];
void dfs(int i,int n){
    v[i]=1; printf("%d ",i);
    for(int j=0;j<n;j++)
        if(g[i][j] && !v[j]) dfs(j,n);
}

