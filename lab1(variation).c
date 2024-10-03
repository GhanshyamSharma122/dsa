#include<stdio.h>
#include<stdlib.h>
#define   SIZE 5
typedef struct stack{
   int top;
   int data[SIZE];
}stack;

int isfull( stack *s){
    return s->top==SIZE-1?1:0;
}
int isempty( stack *s){
    return (s->top==-1)?1:0;
}
void push(int i, stack *s){
    if(isfull(&s)){
        printf("stack overflow\n");
        return;
    }
    s->data[++s->top]=i;
}
int pop( stack *s){
    if(isempty(&s)){
        printf("stack underflow\n");
        return 0;
    }
    return s->data[s->top--];
}
void display( stack *s){
    for(int i=s->top;i>=0;i--){
        printf("%d ",s->data[i]);
    }
    printf("\n");
}
void main(){
     stack s;
    s.top=-1;
    while(1){
        int ch;
        int i;
        printf("main menu \n1.push() 2.pop() 3.display() 4.isempty() 5.isfull() 6.exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            printf("\nenter the number\n");
            scanf("%d",&i);
            push(i,&s);
            break;
            case 2:
            printf("the value popped is %d",pop(&s));
            break;
            case 3:
            printf("the stack elements are axs follows\n");
            display(&s);
            break;
            case 4:
            if(isempty(&s)){
                printf("empty\n");
            
            }else{
                printf("not empty\n");
            }
            break;
            case 5:
            if(isfull(&s)){
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
