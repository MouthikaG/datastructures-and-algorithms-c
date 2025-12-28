#include <stdio.h>
int main(){
    int a[5]={5,4,3,2,1};
    for(int i=0;i<5;i++)
        for(int j=0;j<4;j++)
            if(a[j]>a[j+1]){
                int t=a[j];a[j]=a[j+1];a[j+1]=t;
            }
}

