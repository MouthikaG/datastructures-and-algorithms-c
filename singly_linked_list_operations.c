#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void append(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode; 
    } else {
        struct Node* temp = *head;
        while (temp->next) temp = temp->next;  
        temp->next = newNode;  
    }
}

void printList(struct Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next; 
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;  

    append(&head, 10);
    append(&head, 20);
    append(&head, 30);

    printList(head);

    return 0;
}

