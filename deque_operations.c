#include <stdio.h>
#define SIZE 10
int dq[SIZE],f=-1,r=-1;
int main(){
    dq[++r]=10;
    dq[++r]=20;
    printf("%d %d",dq[f+1],dq[r]);
}

