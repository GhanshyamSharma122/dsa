#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};
typedef struct node *n;

void insertAtHead(n *head, int data) {
    n temp = (n)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = *head;
    *head = temp;
}

void insertAtTail(n *head, int data) {
    n temp = (n)malloc(sizeof(struct node)), t = *head;
    temp->data = data;
    temp->next = NULL;
    if (*head == NULL) {
        *head = temp;
        return;
    }
    while (t->next) {
        t = t->next;
    }
    t->next = temp;
}

void insertAtPos(n *head, int data, int pos) {
    n temp = (n)malloc(sizeof(struct node)), t = *head;
    temp->data = data;
    if (pos == 0 || *head == NULL) {
        insertAtHead(head, data);
        return;
    }
    while (--pos && t != NULL) {
        t = t->next;
    }
    if (t == NULL) {
        printf("The index you gave is invalid\n");
        return;
    }
    temp->next = t->next;
    t->next = temp;
}

void display(n *head) {
    n t = *head;
    if (*head == NULL) {
        printf("Empty linked list\n");
        return;
    }
    printf("\nThe linked list is as follows:\n");
    while (t) {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

void main() {
    int ch;
    n head = NULL;
    while (1) {
        int val, pos;
        printf("\nEnter the option\n1. Insert at head 2. Insert at tail 3. Insert at position 4. Display\n");
        scanf("%d", &ch);
        switch (ch) {
        case 1:
            printf("Enter the value:\n");
            scanf("%d", &val);
            insertAtHead(&head, val);
            break;
        case 2:
            printf("Enter the value:\n");
            scanf("%d", &val);
            insertAtTail(&head, val);
            break;
        case 3:
            printf("Enter the value and position:\n");
            scanf("%d %d", &val, &pos);
            insertAtPos(&head, val, pos);
            break;
        case 4:
            display(&head);
            break;
        default:
            exit(0);
        }
    }
}
