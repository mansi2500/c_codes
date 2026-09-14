#include <stdio.h>

int main() {
    int arr[100];
    int n, choice, element, position;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\n1. Insert at Beginning\n2. Insert in Between\n3. Insert at Last\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter element to insert: ");
    scanf("%d", &element);

    if (choice == 1) {
        for (int i = n; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
        arr[0] = element;
        n++;
    } 
    else if (choice == 2) {
        printf("Enter index position (0 to %d): ", n);
        scanf("%d", &position);
        
        if (position >= 0 && position <= n) {
            for (int i = n; i > position; i--) {
                arr[i] = arr[i - 1];
            }
            arr[position] = element;
            n++;
        } else {
            printf("Invalid position!\n");
            return 1;
        }
    } 
    else if (choice == 3) {
        arr[n] = element;
        n++;
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
