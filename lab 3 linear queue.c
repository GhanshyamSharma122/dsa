// Online C compiler to run C program online
#include <stdio.h>
#define MAX 50
int front=-1;
int rear=-1;
int queue[MAX];
int isEmpty(){
    if(front==-1){
        return 1;
    }
    return 0;
}
int isFull(){
    if(rear==MAX-1)
    return 1;
    return 0;
}
void enqueue(int val){
    if(isFull()){
        printf("queue overflow\n");
    return;
    }
    if(front==-1){
        front=0;
    }
    queue[++rear]=val;
}
int dequeue(){
    if(isEmpty()){
        printf("queue underflow\n");
        return -1;
    }
    int el=queue[front];
    if(front==rear){
        front=rear=-1;
        return el;
    }
    front++;
    return el;
}
void display(){
    if(isEmpty()){
        printf("empty queue\n");
        return;
    }
    printf("\n the elements of the queue are\n");
    for(int i=front;i<=rear;i++){
        printf("%d ",queue[i]);
    }
    printf("\n");
}
void main(){
    int ch;
    int val;
    do{
        printf("the mainmenu is as follows\n");
        printf("1.enqueue\n2.dequeue\n3.isFull\n4.isEmpty\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            printf("enter the value to insert\n");
            scanf("%d",&val);
            enqueue(val);
            display();
            break;
            case 2:
            dequeue();
            display();
            break;
            case 3:
            printf("the queue is %s",isFull()?"full\n":"not full\n");
            break;
            case 4:
            printf("the queue is %s",isEmpty()?"empty\n":"not empty\n");
            break;
        }
    }while (ch!=5);
}
