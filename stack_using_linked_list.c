#include <stdio.h>
#include <stdlib.h>
struct Node{int data; struct Node* next;};
struct Node* top=NULL;
void push(int x){
    struct Node* n=malloc(sizeof(struct Node));
    n->data=x; n->next=top; top=n;
}
void pop(){
    if(!top) return;
    struct Node* t=top;
    top=top->next; free(t);
}
int main(){
    push(10); push(20); pop();
}

