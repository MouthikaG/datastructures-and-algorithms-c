#include <stdio.h>
#define MAX 100
char stack[MAX]; int top=-1;
void push(char c){ stack[++top]=c; }
char pop(){ return stack[top--]; }
int main(){
    char exp[100];
    scanf("%s",exp);
    for(int i=0;exp[i];i++){
        if(exp[i]=='(') push('(');
        else if(exp[i]==')'){
            if(top==-1){ printf("Unbalanced"); return 0;}
            pop();
        }
    }
    printf(top==-1?"Balanced":"Unbalanced");
}

