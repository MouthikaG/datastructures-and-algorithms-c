#include <stdio.h>
#include <stdlib.h>
struct Node{int data; struct Node* l,*r;};
void inorder(struct Node* n){
    if(!n) return;
    inorder(n->l); printf("%d ",n->data); inorder(n->r);
}

