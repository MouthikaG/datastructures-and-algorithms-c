#include <stdio.h>
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
int main(){ printf("%d",gcd(12,8)); }

