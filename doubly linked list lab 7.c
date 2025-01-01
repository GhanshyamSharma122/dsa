#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
};

typedef struct node* nod;

nod head = NULL;

nod createNode(int data) {
    nod temp = (nod)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

void insertAtEnd(int data) {
    nod temp = createNode(data);
    if (head == NULL) {
        head = temp;
    } else {
        nod ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = temp;
        temp->prev = ptr;
    }
}

void deleteNode(int data) {
    nod temp = head;
    while (temp != NULL && temp->data != data) {
        temp = temp->next;
    }
    if (temp == NULL) {
        return;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);
}

void insertLeft(int val, int data) {
    nod temp = head;
    while (temp != NULL && temp->data != data) {
        temp = temp->next;
    }
    if (temp == NULL) {
        return;
    }
    nod newTemp = createNode(val);
    newTemp->next = temp;
    newTemp->prev = temp->prev;
    if (temp->prev != NULL) {
        temp->prev->next = newTemp;
    } else {
        head = newTemp;
    }
    temp->prev = newTemp;
}

void display() {
    if (head == NULL) {
        return;
    }
    nod temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int ch, data, val;

    while(1) {
        printf("Enter your choice\n ");
        printf("1.add at last\n");
        printf("2.add before value\n");
        printf("3.delete the value\n");
        printf("4. Display\n");
        
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 2:
               printf("Enter the value to insert: ");
                scanf("%d", &val);
                printf("Enter the data of the node before which to insert: ");
                scanf("%d", &data);
                insertLeft(val, data);
                break;
            case 3:
                
                 printf("Enter data of node to delete: ");
                scanf("%d", &data);
                deleteNode(data);
                break;
            case 4:
                display();
                break;
            default:
                exit(0);
        }
    } 

    return 0;
}
