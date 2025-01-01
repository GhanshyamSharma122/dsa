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

void deleteAtHead(n *head) {
    if (*head == NULL) {
        printf("Can't delete from an empty linked list\n");
        return;
    }
    n temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteAtTail(n *head) {
    if (*head == NULL) {
        printf("Can't delete from an empty linked list\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    n t = *head;
    while (t->next->next) {
        t = t->next;
    }
    free(t->next);
    t->next = NULL;
}

void deleteAtPos(n *head, int pos) {
    if (*head == NULL) {
        printf("Can't delete from an empty linked list\n");
        return;
    }
    if (pos == 0) {
        deleteAtHead(head);
        return;
    }
    n t = *head;
    while (--pos && t->next != NULL) {
        t = t->next;
    }
    if (t->next == NULL) {
        printf("The index you gave is invalid\n");
        return;
    }
    n temp = t->next;
    t->next = temp->next;
    free(temp);
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
        printf("\nEnter the option\n1. Add 2. Delete from head 3. Delete from end 4. Delete from position 5. Display\n");
        scanf("%d", &ch);
        switch (ch) {
        case 1:
            printf("Enter the value:\n");
            scanf("%d", &val);
            insertAtHead(&head, val);
            break;
        case 2:
            deleteAtHead(&head);
            break;
        case 3:
            deleteAtTail(&head);
            break;
        case 4:
            printf("Enter the position:\n");
            scanf("%d", &pos);
            deleteAtPos(&head, pos);
            break;
        case 5:
            display(&head);
            break;
        default:
            exit(0);
        }
    }
}
