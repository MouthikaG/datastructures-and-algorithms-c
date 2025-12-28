#include <stdio.h>
#define MAX 100
int stack[MAX],top=-1;
void push(int x){ stack[++top]=x; }
int pop(){ return stack[top--]; }
int main(){
    char exp[100];
    scanf("%s",exp);
    for(int i=0;exp[i];i++){
        if(exp[i]>='0'&&exp[i]<='9')
            push(exp[i]-'0');
        else{
            int b=pop(),a=pop();
            switch(exp[i]){
                case '+':push(a+b);break;
                case '-':push(a-b);break;
                case '*':push(a*b);break;
                case '/':push(a/b);break;
            }
        }
    }
    printf("%d",pop());
}

