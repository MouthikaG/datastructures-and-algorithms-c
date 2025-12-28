#include <stdio.h>
void toh(int n,char a,char b,char c){
    if(n==0) return;
    toh(n-1,a,c,b);
    printf("%c -> %c\n",a,c);
    toh(n-1,b,a,c);
}
int main(){ toh(3,'A','B','C'); }

