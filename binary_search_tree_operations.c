#include <stdio.h>
#include <stdlib.h>
struct Node{int data; struct Node* l,*r;};
struct Node* insert(struct Node* r,int x){
    if(!r){
        r=malloc(sizeof(*r));
        r->data=x; r->l=r->r=NULL;
    }
    else if(x<r->data) r->l=insert(r->l,x);
    else r->r=insert(r->r,x);
    return r;
}

