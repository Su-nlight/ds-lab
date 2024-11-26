#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* create_node(int data){
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    if (new == NULL){
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
    //example graph
    struct Node* root = create_node(1);
    root->left = create_node(2);
    root->right = create_node(3);
    root->left->left = create_node(4);
    root->left->right = create_node(5);
    do{
        printf("\nEnter the choice from menu: ");
        scanf("%d",&choice);
        switch(choice){
            case(1): {inorder_traversal(root);break;}
            case(2): {preorder_traversal(root);break;}
            case(3): {postorder_traversal(root);break;}
            case(4): {flag=0;break;}
            default: {printf("Invalid choice.");break;}
        }
    }while(flag);
}
