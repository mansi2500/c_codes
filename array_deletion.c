#include <stdio.h>

int main() {
    int arr[100];
    int n, choice, position;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Array is empty!\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\n1. Delete from Beginning\n2. Delete from Between\n3. Delete from Last\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        for (int i = 0; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--;
    } 
    else if (choice == 2) {
        printf("Enter index position to delete (0 to %d): ", n - 1);
        scanf("%d", &position);
        
        if (position >= 0 && position < n) {
            for (int i = position; i < n - 1; i++) {
                arr[i] = arr[i + 1];
            }
            n--;
        } else {
            printf("Invalid position!\n");
            return 1;
        }
    } 
    else if (choice == 3) {
        n--;
    } 
    else {
        printf("Invalid choice!\n");
        return 1;
    }

    printf("Updated array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
