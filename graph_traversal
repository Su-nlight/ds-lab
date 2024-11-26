#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct node* left;
    struct node* right;
}

struct Node* create_node(int data){
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    if (new == Null){
        printf("Overflow");
        return NULL;
    }
    new->data = data;
    new->left = new->right = NULL;
    return new;
}

void inorder_traversal(struct Node* node){
    if( node == NULL ){
        return;
    }
    inorder_traversal(node->left);
    printf("%d  ", node->data);
    inorder_traversal(node->right);
}

void preorder_traversal(struct Node* node){
    if( node == NULL ){
        return;
    }
    printf("%d  ", node->data);
    inorder_traversal(node->left);
    inorder_traversal(node->right);
}

void postorder_traversal(struct Node* node){
    if( node == NULL ){
        return;
    }
    inorder_traversal(node->left);
    inorder_traversal(node->right);
    printf("%d  ", node->data);
}

void main() {
    int flag=1, choice;
    printf("Menu: \n");
    do{
        
    }while(flag)
}
