// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>
struct n{
    int data;
    struct n *left,*right;
};
typedef struct n *node;
node createNode(int data){
    node temp=(node)malloc(sizeof(struct n));
    temp->data=data;
    temp->left=temp->right=NULL;
    return temp;
}

node insert(node root,int data){
    if(root==NULL){
        return createNode(data);
    }
    else if(data<root->data){
        root->left=insert(root->left,data);
    }else if(data>root->data){
        root->right=insert(root->right,data);
    }
    return root;
    
}
void preorder(node root){
    if(root==NULL){
        return ;
    }
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(node root){
    if(root==NULL){
        return ;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}
void inorder(node root){
    if(root==NULL){
        return ;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}


int main(){
    node root=NULL;
    int ch;
    int data;
    do{
        printf("enter the choice 1.insert 2.preorder 3.postorder 4.inorder 5.exit");
        printf("\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            printf("enter the data to put in the tree\n");
            scanf("%d",&data);
            root=insert(root,data);
            break;
            
            case 2:
            preorder(root);
            printf("\n");
            break;
            
            
            case 3:
            postorder(root);
            printf("\n");
            break;
            
            
            case 4:
            inorder(root);
            printf("\n");
            break;
            
            case 5:
            exit(0);
            break;
        }
        
        
        
    }while(1);
    return 0;
}
