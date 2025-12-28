#include <stdio.h>
void createArray(int arr[], int *size) {
 printf("Enter the number of elements: ");
 scanf("%d", size);
 if (*size == 0) {
 printf("ERROR! Please enter a valid number.\n");
 return; 
 }
 printf("Enter the elements:\n");
 for (int i = 0; i < *size; i++) {
 scanf("%d", &arr[i]);
 }
}
void insertElement(int arr[], int *size, int max_size) {
 if (*size >= max_size) {
 printf("Array is full. Cannot insert more elements.\n");
 return;
 }
 int pos, value;
 printf("Enter the position (1 to %d) and value to insert: ", 
*size + 1);
 scanf("%d %d", &pos, &value);
 for (int i = *size; i >= pos; i--) {
 arr[i] = arr[i - 1];
 }
 arr[pos - 1] = value;
 (*size)++;
 printf("Element inserted successfully.\n");
}
void deleteElement(int arr[], int *size) {
 if (*size == 0) {
 printf("Array is empty. Nothing to delete.\n");
 return;
 }
 int pos;
 printf("Enter the position (1 to %d) of the element to delete: ", *size);
 scanf("%d", &pos);
 for (int i = pos - 1; i < *size - 1; i++) {
 arr[i] = arr[i + 1];
 }
 (*size)--;
 printf("Element deleted successfully.\n");
}
void findElement(int arr[], int size) {
 int value, found = 0;
 printf("Enter the element to search for: ");
 scanf("%d", &value);
 for (int i = 0; i < size; i++) {
 if (arr[i] == value) {
 printf("Element found at position %d.\n", i + 1);
 found = 1;
 break;
 }
 }
 if (!found) {
 printf("Element not found in the array.\n");
 }
}
void sortArray(int arr[], int size) {
 for (int i = 0; i < size - 1; i++) {
 for (int j = 0; j < size - i - 1; j++) {
 if (arr[j] > arr[j + 1]) {
 int temp = arr[j];
 arr[j] = arr[j + 1];
 arr[j + 1] = temp;
 }
 }
 }
 printf("Array sorted successfully.\n");
}
void displayArray(int arr[], int size) {
 if (size == 0) {
 printf("Array is empty.\n");
 return;
 }
 printf("Array elements: ");
 for (int i = 0; i < size; i++) {
 printf("%d ", arr[i]);
 }
 printf("\n");
}
int main() {
 int arr[100]; 
 int size = 0, max_size = 100, choice;
 do {
 printf("\nMenu:\n");
 printf("1. Create Array\n");
 printf("2. Insert Element\n");
 printf("3. Delete Element\n");
 printf("4. Find Element\n");
 printf("5. Sort Array\n");
 printf("6. Display Array\n");
 printf("7. Exit\n");
 printf("Enter your choice: ");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 createArray(arr, &size);
 break;
 case 2:
 insertElement(arr, &size, max_size);
 break;
 case 3:
 deleteElement(arr, &size);
 break;
 case 4:
 findElement(arr, size);
 break;
 case 5:
 sortArray(arr, size);
 break;
 case 6:
 displayArray(arr, size);
 break;
 case 7:
 printf("Exiting program.\n");
 break;
 default:
 printf("Invalid choice! Please try again.\n");
 }
 } while (choice != 7);
 return 0;
}

