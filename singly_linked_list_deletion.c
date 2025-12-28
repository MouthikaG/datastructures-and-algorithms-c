#include <stdio.h>
#include <stdlib.h>
struct Node{int data; struct Node* next;};
int main(){
    struct Node *h=malloc(sizeof(struct Node));
    h->data=10; h->next=NULL;
    free(h);
}

