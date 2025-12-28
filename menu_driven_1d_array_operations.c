#include <stdio.h>
int main()
{
    int choice, n, i, j, element, pos, temp, tempArr[100];
    int arr1D[100];
    printf("UNIQUE ID:E0524017\n");
    printf("Enter the size of the 1D array:");
    scanf("%d", &n);
    printf("Enter %d elements for the 1D array:\n", n);
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &arr1D[i]);
    }

    do {
        printf("\n1. Insert an element into the 1D array\n");
        printf("2. Delete an element from the 1D array\n");
        printf("3. Find an element in the 1D array\n");
        printf("4. Sort the 1D array\n");
        printf("5. Display the 1D array\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                printf("Enter the position to insert (1 to %d): ", n + 1);
                scanf("%d", &pos);
                if (pos < 1 || pos > n + 1) {
                    printf("Invalid position!\n");
                } else {
                    for (i = n; i >= pos; i--) {
                        arr1D[i] = arr1D[i - 1];
                    }
                    arr1D[pos - 1] = element;
                    n++;
                }
                break;

            case 2:
                printf("Enter the position to delete (1 to %d): ", n);
                scanf("%d", &pos);
                if (pos < 1 || pos > n)
                {
                printf("Invalid position!\n");
                } else 
                {
                    for (i = pos - 1; i < n - 1; i++) 
                    {
                        arr1D[i] = arr1D[i + 1];
                    }
                    n--;
                }
                break;

            case 3:
                printf("Enter the element to find: ");
                scanf("%d", &element);
                for (i = 0; i < n; i++)
                {
                    if (arr1D[i] == element) {
                        printf("Element %d found at position %d.\n", element, i + 1);
                        break;
                    }
                }
                if (i == n)
                {
                    printf("Element %d not found.\n", element);
                }
                break;

            case 4:
                for (i = 0; i < n; i++)
                {
                    tempArr[i] = arr1D[i];
                }

                for (i = 0; i < n - 1; i++) 
                {
                    for (j = i + 1; j < n; j++) 
                    {
                        if (tempArr[i] > tempArr[j]) {
                            temp = tempArr[i];
                            tempArr[i] = tempArr[j];
                            tempArr[j] = temp;
                        }
                    }
                }

                for (i = 0; i < n; i++)
                {
                    arr1D[i] = tempArr[i];
                }
                printf("1D array sorted successfully.\n");
                break;

            case 5:
                printf("1D Array elements: ");
                for (i = 0; i < n; i++) {
                    printf("%d ", arr1D[i]);
                }
                printf("\n");
                break;

            case 6:
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    while (choice != 6);

    return 0;
}

