#include <stdio.h>
#include <stdlib.h>
struct Node{int data; struct Node *prev,*next;};
int main(){
    struct Node* n=malloc(sizeof(struct Node));
    n->data=10; n->prev=n->next=NULL;
}

