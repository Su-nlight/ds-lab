#include<stdio.h>
#include<stdlib.h>

struct node
{
        int exponent;
        int coefficient;
        struct node *link;
};
struct node* start_poly1=NULL;
struct node* start_poly2=NULL;

struct Node *insertEnd(struct Node *HEAD, struct Node *newNode) {

  if (HEAD == NULL)
    return newNode;

  struct Node *ptr = HEAD;

  while (ptr->link != NULL)
    ptr = ptr->link;

  ptr->link = newNode;
  newNode->link = NULL;

  return HEAD;
}

struct node *create(){
    struct Node *HEAD = NULL;

  while (1) {

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node *));

    printf("Enter the coefficient: ");
    scanf("%d", &newNode->coefficient);

    printf("Enter the exponent: ");
    scanf("%d", &newNode->exponent);

    HEAD = insertEnd(HEAD, newNode);

    int choice;
    printf("Enter 0 to exit and 1 to continue adding more terms: ");
    scanf("%d", &choice);

    if (choice == 0) return HEAD;
    }
}
struct Node *add(struct Node *first, struct Node *second) {

  struct Node *HEAD = NULL;

  while (first != NULL && second != NULL) {

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node *));

    if (first->exponent > second->exponent) {

      newNode->exponent = first->exponent;
      newNode->coefficient = first->coefficient;

      first = first->link;

    } else if (second->exponent > first->exponent) {

      newNode->exponent = second->exponent;
      newNode->coefficient = second->coefficient;

      second = second->link;

    } else {

      newNode->exponent = first->exponent;
      newNode->coefficient = first->coefficient + second->coefficient;

      first = first->link;
      second = second->link;
    }

    HEAD = insertEnd(HEAD, newNode);
  }

  while (first != NULL || second != NULL) {

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node *));

    if (first != NULL) {

      newNode->exponent = first->exponent;
      newNode->coefficient = first->coefficient;

      first = first->link;

    } else {

      newNode->exponent = second->exponent;
      newNode->coefficient = second->coefficient;

      second = second->link;
    }

    HEAD = insertEnd(HEAD, newNode);
  }

  return HEAD;
}

void traverse(struct node *polyn){
    struct node* ptr=polyn;
    for(ptr=start; ptr!=NULL; ptr=ptr->link){
        printf(" + %d^%d", ptr->base, ptr->exponent);
    }
    printf("\n")
}

int main(){
    int flag=1,choice;

    printf("Enter the First polynomial: ");
    start_poly1 = create();
    printf("Enter the Second Polynomial: ");
    start_poly2 = create();

    printf("\nThe First polynomial is: ");
    traverse(start_poly1);
    printf("\nThe second polynomial is: ");
    traverse(start_poly2);

    traverse(add(start_poly1, start_poly2))
    
    return 0;
}
