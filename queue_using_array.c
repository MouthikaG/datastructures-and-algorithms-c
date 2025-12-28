#include <stdio.h>
#include <stdlib.h>

#define SIZE 10  

int queue[SIZE], front = -1, rear = -1;


void enqueue() {
    int value;
    if (rear == SIZE - 1) {
        printf("Queue is full!\n");
        return;
    }
    printf("Enter value to enqueue: ");
    scanf("%d", &value);
    
    if (front == -1) front = 0;
    queue[++rear] = value;
    printf("Enqueued %d\n", value);
}


void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Dequeued %d\n", queue[front++]);
    
    if (front > rear) front = rear = -1;  
}


void menu() {
    int choice;
    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: printf("Exit...\n"); exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
}

int main() {
    menu(); 
	return 0;    
}
