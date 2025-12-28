#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void insertAtBeginning(struct node** r, int value) {
    struct node* p;
    p = (struct node*)malloc(sizeof(struct node));
    p->data = value;
    p->next = *r;
    *r = p;
}

void insertAtEnd(struct node** r, int value) {
    struct node* p, * q;
    p = (struct node*)malloc(sizeof(struct node));
    p->data = value;
    p->next = NULL;
    if (*r == NULL)
        *r = p;
    else {
        q = *r;
        while (q->next != NULL)
            q = q->next;
        q->next = p;
    }
}

void insertAtPosition(struct node** r, int value, int position) {
    struct node* p, * q;
    p = (struct node*)malloc(sizeof(struct node));
    p->data = value;
    if (*r == NULL || position == 1) {
        p->next = *r;
        *r = p;
    } else {
        q = *r;
        for (int i = 1; i < position - 1 && q != NULL; i++) {
            q = q->next;
        }
        if (q != NULL) {
            p->next = q->next;
            q->next = p;
        }
    }
}

void traverse(struct node* r) {
    printf("Linked List: ");
    while (r != NULL) {
        printf("%d -> ", r->data);
        r = r->next;
    }
    printf("NULL\n");
}

int main() {
    struct node* r = NULL;
    int choice, value, position;

    while (1) {
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Traverse and print list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                insertAtBeginning(&r, value);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertAtEnd(&r, value);
                break;
            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position to insert: ");
                scanf("%d", &position);
                insertAtPosition(&r, value, position);
                break;
            case 4:
                traverse(r);
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please choose a valid option.\n");
        }
    }
}
