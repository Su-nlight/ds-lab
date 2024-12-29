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
void insert_node(int data, struct Node** root) {
    if (*root == NULL) {
        struct Node* ptr = create_node(data);
        if (ptr == NULL) return;
        *root = ptr;
    }
    else if (data >= (*root)->data) {
        insert_node(data, &(*root)->right);
    }
    else {
        insert_node(data, &(*root)->left);
    }
}

struct Node* find_min(struct Node* node) {
    while (node && node->left != NULL) {
        node = node->left;
    }
    return node;
}

void delete_node(int data, struct Node** root){
    if(*root == Null){
        // underflow condition
        printf("Underflow\n");
        return;
        // this is a test line
    }
    if (data < (*root)->data) {
        delete_node(&(*root)->left, data);
    } else if (data > (*root)->data) {
        delete_node(&(*root)->right, data);
    } else {
        // case for no children
        if ((*root)->left == NULL && (*root)->right == NULL) {
            free(*root);
            *root = NULL;
        }
        // case for one child
        else if ((*root)->left == NULL) {
            struct Node* temp = *root;
            *root = (*root)->right;
            free(temp);
        } else if ((*root)->right == NULL) {
            struct Node* temp = *root;
            *root = (*root)->left;
            free(temp);
        }
        // case for two children
        else {
            struct Node* temp = find_min((*root)->right);
            (*root)->data = temp->data;
            delete_node(&(*root)->right, temp->data);
        }
    }
}

void inorder_traversal(struct Node* node){
    if( node == NULL ){
        return;
    }
    inorder_traversal(node->left);
    printf("%d  ", node->data);
    inorder_traversal(node->right);
}

void main() {
    int flag=1, choice;
    printf("Menu: \n");
    printf("1. Insert to BST\n");
    printf("2. Delete from BST\n");
    printf("3. inorder traversal\n");
    printf("4. exit\n");
    //example graph
    struct Node* root = NULL;
    
    do{
        printf("\nEnter the choice from menu: ");
        scanf("%d",&choice);
        switch(choice){
            case(1): {
                int data;
                printf("Enter data you want to insert: ");
                scanf("%d",&data);
                insert_node(data, &root);
                break;
            }
            case(2): {
                int data;
                printf("Enter the data you want to Delete: ");
                scanf("%d". &data);
                delete_node(data, &root);
                break;
            }
            case(3): {inorder_traversal(root);break;}
            case(4): {flag=0;break;}
            default: {printf("Invalid choice.");break;}
        }
    }while(flag);
    return;
}
