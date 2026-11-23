#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *create(struct node *head) {
    struct node *newnode, *temp;
    int n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &newnode->data);

        newnode->prev = NULL;
        newnode->next = NULL;

        if(head == NULL) {
            head = newnode;
            temp = newnode;
        }
        else {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
    }

    return head;
}

struct node *insert_left(struct node *head) {
    struct node *newnode, *temp;
    int value;

    printf("Enter the value of selected node: ");
    scanf("%d", &value);

    temp = head;

    while(temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("Node not found\n");
        return head;
    }

    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter new data: ");
    scanf("%d", &newnode->data);

    newnode->prev = temp->prev;
    newnode->next = temp;

    if(temp->prev != NULL) {
        temp->prev->next = newnode;
    }
    else {
        head = newnode;
    }

    temp->prev = newnode;

    return head;
}

struct node *delete_value(struct node *head) {
    struct node *temp;
    int value;

    printf("Enter value to delete: ");
    scanf("%d", &value);

    temp = head;

    while(temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("Value not found\n");
        return head;
    }

    if(temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    else {
        head = temp->next;
    }

    if(temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);

    printf("Deleted successfully\n");

    return head;
}

void display(struct node *head) {
    struct node *temp = head;

    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("NULL <-> ");

    while(temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {
    struct node *head = NULL;
    int choice;

    while(1) {
        printf("\n1. Create");
        printf("\n2. Insert to the left of selected node");
        printf("\n3. Delete based on value");
        printf("\n4. Display");
        printf("\n5. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                head = create(head);
                break;

            case 2:
                head = insert_left(head);
                break;

            case 3:
                head = delete_value(head);
                break;

            case 4:
                display(head);
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

