include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int n, value, choice, position;

    printf("Enter number of initial nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    printf("\n1. Insert at Beginning\n2. Insert in Between\n3. Insert at End\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter data to insert: ");
    scanf("%d", &value);

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (choice == 1) {
        newNode->next = head;
        head = newNode;
    } 
    else if (choice == 2) {
        printf("Enter position index (starting from 0): ");
        scanf("%d", &position);

        if (position == 0) {
            newNode->next = head;
            head = newNode;
        } else {
            temp = head;
            for (int i = 0; i < position - 1 && temp != NULL; i++) {
                temp = temp->next;
            }
            if (temp != NULL) {
                newNode->next = temp->next;
                temp->next = newNode;
            } else {
                printf("Invalid position!\n");
                free(newNode);
                return 1;
            }
        }
    } 
    else if (choice == 3) {
        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    } 
    else {
        printf("Invalid choice!\n");
        free(newNode);
        return 1;
    }

    printf("\nUpdated Linked List: ");
    temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    temp = head;
    while (temp != NULL) {
        struct Node* nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }

    return 0;
}
