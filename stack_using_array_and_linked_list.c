#include <stdio.h>
#include <stdlib.h>

#define MAX 1000


struct StackArray {
    int top;
    int arr[MAX];
};

void initStackArray(struct StackArray* stack) {
    stack->top = -1;
}

int isEmptyArray(struct StackArray* stack) {
    return stack->top == -1;
}

int isFullArray(struct StackArray* stack) {
    return stack->top == MAX - 1;
}

void pushArray(struct StackArray* stack, int item) {
    if (isFullArray(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->arr[++(stack->top)] = item;
}

int popArray(struct StackArray* stack) {
    if (isEmptyArray(stack)) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack->arr[(stack->top)--];
}

int peekArray(struct StackArray* stack) {
    if (isEmptyArray(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->arr[stack->top];
}

// Stack using Linked List
struct Node {
    int data;
    struct Node* next;
};

struct StackLinkedList {
    struct Node* head;
};

void initStackLinkedList(struct StackLinkedList* stack) {
    stack->head = NULL;
}

int isEmptyLinkedList(struct StackLinkedList* stack) {
    return stack->head == NULL;
}

void pushLinkedList(struct StackLinkedList* stack, int item) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = item;
    new_node->next = stack->head;
    stack->head = new_node;
}

int popLinkedList(struct StackLinkedList* stack) {
    if (isEmptyLinkedList(stack)) {
        printf("Stack underflow\n");
        return -1;
    }
    struct Node* temp = stack->head;
    int popped = temp->data;
    stack->head = stack->head->next;
    free(temp);
    return popped;
}

int peekLinkedList(struct StackLinkedList* stack) {
    if (isEmptyLinkedList(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->head->data;
}

// Main function to demonstrate both implementations
int main() {
    int choice;
    printf("Choose Stack Implementation:\n");
    printf("1. Stack using Array\n");
    printf("2. Stack using Linked List\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: {
            printf("Stack using Array:\n");
            struct StackArray stack;
            initStackArray(&stack);
            printf("Is stack empty? %d\n", isEmptyArray(&stack));
            pushArray(&stack, 10);
            pushArray(&stack, 20);
            pushArray(&stack, 30);
            printf("Top element: %d\n", peekArray(&stack));
            printf("Popped element: %d\n", popArray(&stack));
            printf("Is stack empty? %d\n", isEmptyArray(&stack));
            break;
        }
        case 2: {
            printf("Stack using Linked List:\n");
            struct StackLinkedList stack;
            initStackLinkedList(&stack);
            printf("Is stack empty? %d\n", isEmptyLinkedList(&stack));
            pushLinkedList(&stack, 10);
            pushLinkedList(&stack, 20);
            pushLinkedList(&stack, 30);
            printf("Top element: %d\n", peekLinkedList(&stack));
            printf("Popped element: %d\n", popLinkedList(&stack));
            printf("Is stack empty? %d\n", isEmptyLinkedList(&stack));
            break;
        }
        default:
            printf("Invalid choice\n");
            break;
    }

}

