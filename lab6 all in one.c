1.sort
#include <stdio.h>
#include <stdlib.h>

struct n {
    int data;
    struct n *next;
};
typedef struct n *node;

node insertAtHead(int data, node head) {
    node temp = (node)malloc(sizeof(struct n));
    temp->data = data;
    temp->next = NULL;
    if (head == NULL)
        return temp;
    temp->next = head;
    head = temp;
    return head;
}

node bubbleSort(node head) {
    node end = NULL;
    int swap = 0;
    while (1) {
        node curr;
        swap = 0;
        for (curr = head; curr->next != end; curr = curr->next) {
            if (curr->data > curr->next->data) {
                int temp = curr->data;
                curr->data = curr->next->data;
                curr->next->data = temp;
                swap = 1;
            }
        }
        end = curr;
        if (!swap)
            break;
    }
    return head;
}

void display(node head) {
    if (head == NULL) {
        printf("The list is empty\n");
        return;
    }
    node curr = head;
    while (curr) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    node head = NULL;
    head = insertAtHead(1, head);
    head = insertAtHead(2, head);
    head = insertAtHead(3, head);
    head = insertAtHead(4, head);
    // this will be inserted such as 4 3 2 1
    printf("Original List: ");
    display(head);

    head = bubbleSort(head);
    printf("Sorted List: ");
    display(head);

    return 0;
}

2.reverse
#include <stdio.h>
#include <stdlib.h>

struct n {
    int data;
    struct n *next;
};
typedef struct n *node;

node insertAtHead(int data, node head) {
    node temp = (node)malloc(sizeof(struct n));
    temp->data = data;
    temp->next = NULL;
    if (head == NULL)
        return temp;
    temp->next = head;
    head = temp;
    return head;
}

node reverse(node head) {
    node prev = NULL;
    node curr = head;
    while (curr) {
        node temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    head = prev;
    return head;
}

void display(node head) {
    if (head == NULL) {
        printf("The list is empty\n");
        return;
    }
    node curr = head;
    while (curr) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    node head = NULL;
    head = insertAtHead(7, head);
    head = insertAtHead(3, head);
    head = insertAtHead(4, head);
    head = insertAtHead(5, head);

    printf("Original List: ");
    display(head);

    head = reverse(head);
    printf("Reversed List: ");
    display(head);

    return 0;
}

3.concatenate
#include <stdio.h>
#include <stdlib.h>

struct n {
    int data;
    struct n *next;
};
typedef struct n *node;

node insertAtHead(int data, node head) {
    node temp = (node)malloc(sizeof(struct n));
    temp->data = data;
    temp->next = NULL;
    if (head == NULL)
        return temp;
    temp->next = head;
    head = temp;
    return head;
}

node concatenate(node l1, node l2) {
    if (l1 == NULL) {
        return l2;
    }
    if (l2 == NULL) {
        return l1;
    }
    node temp = l1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = l2;
    return l1;
}

void display(node head) {
    if (head == NULL) {
        return;
    }
    node curr = head;
    while (curr) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    node head1 = NULL, head2 = NULL;
    head1 = insertAtHead(1, head1);
    head1 = insertAtHead(2, head1);
    head1 = insertAtHead(3, head1);

    head2 = insertAtHead(8, head2);
    head2 = insertAtHead(9, head2);
    head2 = insertAtHead(10, head2);
    head1 = concatenate(head1, head2);
    display(head1);

    return 0;
}


4.stack

#include <stdio.h>
#include <stdlib.h>

struct n {
    int data;
    struct n *next;
};
typedef struct n *node;

node top = NULL;

int isEmpty() {
    return top == NULL;
}

void push(int data) {
    if(top==NULL){
        top= (node)malloc(sizeof(struct n)); 
        top->data=data;
        top->next=NULL;
    }else{
    node temp = (node)malloc(sizeof(struct n)); 
    temp->data = data;
    temp->next = top;  
    top = temp;    
    }
}
void pop() {
    if (isEmpty()) {
        printf("The stack is empty\n");
        return;
    }
    node temp = top;
    top = top->next;  // Update top to the next node
    free(temp);       // Free the popped node
}

void display(node head) {
    if (head == NULL) {
        return;
    }
    node curr = head;
    while (curr) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    push(4);
    push(5);
    push(6);
    display(top);

    pop();
    display(top);

    pop();
    display(top);

    return 0;
}


5.queue
#include <stdio.h>
#include <stdlib.h>

struct n {
    int data;
    struct n *next;
};
typedef struct n *node;

node front = NULL, rear = NULL;

int isEmpty() {
    return front == NULL;
}

void enqueue(int data) {
    node temp = (node)malloc(sizeof(struct n));
    temp->data = data;
    temp->next = NULL;

    if (isEmpty()) {
        front = rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
}

void dequeue() {
    if (isEmpty()) {
        return;
    }
    node temp = front;
    front = front->next;
    if (front == NULL) {
        rear = NULL;
    }
    free(temp);
}

void display() {
    if (isEmpty()) {
        return;
    }
    node curr = front;
    while (curr) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    display();

    dequeue();
    display();

    dequeue();
    display();

    return 0;
}


