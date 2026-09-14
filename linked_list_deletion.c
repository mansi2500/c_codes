#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL, *toDelete = NULL;
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

    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return 0;
    }

    printf("\n1. Delete from Beginning\n2. Delete from Between\n3. Delete from End\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        toDelete = head;
        head = head->next;
        free(toDelete);
    } 
    else if (choice == 2) {
        printf("Enter position index to delete (starting from 0): ");
        scanf("%d", &position);

        if (position == 0) {
            toDelete = head;
            head = head->next;
            free(toDelete);
        } else {
            temp = head;
            for (int i = 0; i < position - 1 && temp != NULL; i++) {
                temp = temp->next;
            }
            if (temp != NULL && temp->next != NULL) {
                toDelete = temp->next;
                temp->next = temp->next->next;
                free(toDelete);
            } else {
                printf("Invalid position!\n");
                return 1;
            }
        }
    } 
    else if (choice == 3) {
        if (head->next == NULL) {
            free(head);
            head = NULL;
        } else {
            temp = head;
            while (temp->next->next != NULL) {
                temp = temp->next;
            }
            toDelete = temp->next;
            temp->next = NULL;
            free(toDelete);
        }
    } 
    else {
        printf("Invalid choice!\n");
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
