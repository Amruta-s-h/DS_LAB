
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void create(struct Node **head, int value) {
    struct Node *newNode, *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    temp = *head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void insertBeginning(struct Node **head, int value) {
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

void insertEnd(struct Node **head, int value) {
    create(head, value);
}

void insertPosition(struct Node **head, int value, int position) {
    struct Node *newNode, *temp;
    int i;

    if (position < 1) {
        printf("Invalid position!\n");
        return;
    }

    if (position == 1) {
        insertBeginning(head, value);
        return;
    }

    temp = *head;

    for (i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position!\n");
        return;
    }

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;
}

void display(struct Node *head) {
    struct Node *temp;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {
    struct Node *head = NULL;
    int choice, value, position;

    while (1) {
        printf("\n1. Create");
        printf("\n2. Insert at Beginning");
        printf("\n3. Insert at Any Position");
        printf("\n4. Insert at End");
        printf("\n5. Display");
        printf("\n6. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                create(&head, value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertBeginning(&head, value);
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &position);
                insertPosition(&head, value, position);
                break;

            case 4:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(&head, value);
                break;

            case 5:
                display(head);
                break;

            case 6:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
