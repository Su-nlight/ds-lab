#include<stdio.h>
#include<stdlib.h>

struct node
{
        int info;
        struct node *link;
};
struct node *start=NULL;
void create();
void traverse();#include<stdio.h>
#include<stdlib.h>

struct node
{
        int info;
        struct node *link;
};
struct node* start=NULL;

void create(){
    struct node* ptr;
    ptr=(struct node*) malloc(sizeof(struct node));
    printf("Enter the information to be stored in node: ");
    scanf("%d",&ptr->info);
    ptr->link=NULL;
    start=ptr;
}

void traverse(){
    struct node* ptr;
    int nodeno=0;
    for(ptr=start; ptr!=NULL; ptr=ptr->link,nodeno++){
        printf("Node no.%d has info = %d", nodeno, ptr->info);
    }
}
int main(){
    create();
    traverse();
    return 0;
}
void main(){
    void create();
    void traverse();
}

void create(){
    struct node *ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    printf("Enter the information to be stored in node: ");
    scanf("%d",&ptr->info);
    ptr->link=NULL;
    start=ptr;
}

void traverse(){
    struct node *ptr;
    int nodeno=0;
    for(ptr=start; ptr!=NULL; ptr=ptr->link,nodeno++){
        print("Node no.%d has info = %d", nodeno, ptr->info);
    }
}
