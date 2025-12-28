#include <stdio.h>
#define SIZE 5
int q[SIZE],f=-1,r=-1;
void enqueue(int x){
    if((r+1)%SIZE==f) return;
    if(f==-1) f=0;
    r=(r+1)%SIZE;
    q[r]=x;
}
int main(){
    enqueue(10); enqueue(20);
}

