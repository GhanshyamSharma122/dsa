#include<stdio.h>
#include<stdlib.h>
#define   SIZE 5
int top=-1;
int stack[SIZE];
int isfull(){
    return top==SIZE-1?1:0;
}
int isempty(){
    return (top==-1)?1:0;
}
void push(int i){
    if(isfull()){
        printf("stack overflow\n");
        return;
    }
    stack[++top]=i;
}
int pop(){
    if(isempty()){
        printf("stack underflow\n");
        return 0;
    }
    return stack[top--];
}
void display(){
    for(int i=top;i>=0;i--){
        printf("%d ",stack[i]);
    }
    printf("\n");
}
void main(){
    while(1){
        int ch;
        int i;
        printf("main menu \n1.push() 2.pop() 3.display() 4.isempty() 5.isfull() 6.exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            printf("\nenter the number\n");
            scanf("%d",&i);
            push(i);
            break;
            case 2:
            printf("the value popped is %d",pop());
            break;
            case 3:
            printf("the stack elements are axs follows\n");
            display();
            break;
            case 4:
            if(isempty()){
                printf("empty\n");
            
            }else{
                printf("not empty\n");
            }
            break;
            case 5:
            if(isfull()){
                printf("full\n");
            
            }else{
                printf("not full\n");
            }
            break;
            case 6:
            exit(0);
            break;
        }
    }
}
