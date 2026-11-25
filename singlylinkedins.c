
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert_begin() {
    struct node *newnode = malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = head;
    head = newnode;
}

void insert_end() {
    struct node *newnode = malloc(sizeof(struct node));
    struct node *temp = head;

    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if (head == NULL)
        head = newnode;
    else {
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newnode;
    }
}

void insert_position() {
    struct node *newnode, *temp = head;
    int pos, i;

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos < 1) {
        printf("Invalid position!\n");
        return;
    }

    if (pos == 1) {
        insert_begin();
        return;
    }

    for (i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid position!\n");
        return;
    }

    newnode = malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = temp->next;
    temp->next = newnode;
}

void display() {
    struct node *temp = head;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n1.Insert Beginning\n");
        printf("2.Insert End\n");
        printf("3.Insert Position\n");
        printf("4.Display\n5.Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert_begin(); break;
            case 2: insert_end(); break;
            case 3: insert_position(); break;
            case 4: display(); break;
            case 5: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
}
