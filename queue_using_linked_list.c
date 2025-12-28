#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* front = NULL;
struct Node* rear = NULL;


void enqueue() {
    int value;
    printf("Enter the value to enqueue: ");
    scanf("%d", &value);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {  
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("\n");
}


void dequeue() {
    if (front == NULL) {
        printf("Queue is empty!\n");
        return;
    }
    struct Node* temp = front;
    printf("Dequeued: %d\n\n", front->data);
    front = front->next;

    if (front == NULL) rear = NULL;  // Reset rear if queue becomes empty
    free(temp);
}


void menu() {
    int choice;
    while (1) {
        printf("Queue Operations:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: printf("\n=== Code Execution Successful ===\n"); exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
}

int main() {
    menu();  
    return 0;
}

