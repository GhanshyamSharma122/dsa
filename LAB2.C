// Online C compiler to run C program online
#include <stdio.h>
#include<ctype.h>
#define MAX 50
int top=-1;
char stack[MAX];
void push(char a){
    stack[++top]=a;
}
char pop(){
    return stack[top--];
}
int pr(char a){
    if(a=='*' || a=='/')
    return 2;
    if(a=='+' || a=='-')
    return 1;
    return 0;
}
int main() {
    char infix[MAX],postfix[MAX];
    int i=0,k=0;
    printf("enter the infix expression\n");
    scanf("%s",infix);
    push('#');
    char ch;
    while((ch=infix[i++])!='\0'){
        if(ch=='(')
        push(ch);
        else if(isalnum(ch))
        postfix[k++]=ch;
        else if(ch==')'){
            while(stack[top]!='(')
            postfix[k++]=pop();
            pop();
        }else{
            while (stack[top]!='#' && pr(stack[top])>=pr(ch))
            postfix[k++]=pop();
            push(ch);
        }
    }
    while (stack[top]!='#')
            postfix[k++]=pop();
    postfix[k]='\0';
    printf("the postfix expression is %s",postfix);
    return 0;
}
