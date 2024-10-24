typedef struct {
    int data[100000];
    int top;
}stack;

void push(char a,stack *st){
    st->data[++(st->top)]=a;
}
char pop(stack *st){
    return st->data[st->top--];
}
char top(stack *st){
    return st->data[st->top];
}
int isEmpty(stack *st){
    return st->top==-1;
}
void  string(stack *st,char *ans){
    int i;
    for(i=0;i<=st->top;i++){
        ans[i]=st->data[i];
    }
    ans[i]='\0';
    
}
char* removeDuplicates(char* s) {
    stack *st =(stack*) malloc(sizeof(stack));
    st->top=-1;
    for(int i=0;s[i]!='\0';i++){
        if(!isEmpty(st) && s[i]==top(st)){
            pop(st);
        }else{
            push(s[i],st);
        }
    }
    char *ans =(char *)malloc(sizeof(char)*100000);
    string(st,ans);
    return ans;
}
