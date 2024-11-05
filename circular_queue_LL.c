#include<stdio.h>
#include<stdlib.h>

struct node
{
        int info;
        struct node *link;
};
struct node* front=NULL;
struct node* rear=NULL;

struct node* create_node(int data){
    struct node* ptr;
    ptr=(struct node*) malloc(sizeof(struct node));
    if(ptr==NULL){
        printf("Overflow");
        return NULL;
    }
    ptr->link=NULL;
    ptr->info=data;
    return ptr;
}

void Enqueue(){
    struct node* new;
    int data;
    printf("Enter the information to be stored in queue: ");
    scanf("%d",&data);
    new = create_node(data);
    if(new==NULL){ return;}
    new->link=front;
    if(rear==NULL){
        front=rear=new;
    }
    else{
        rear->link=new;
        rear=new;
    }
    
}

void Dequeue(){
    if(front==NULL){
        printf("Underflow");
        return;
    }
    struct node* tobedel=front;
    printf("Dequeued data is : %d",tobedel->info);
    if(front==rear){
        front=rear=NULL;
    }
    else{
        front=front->link;
        rear->link=front;
    }
    free(tobedel);
    
}

void traverse(){
    struct node* ptr=front;
    int nodeno=0;
    do{
        printf("Node no.%d has info = %d \n", nodeno+1, ptr->info);
        ptr=ptr->link;
        nodeno++;
    }while(ptr!=front);
}
int main(){
    int flag=1,choice;
    printf("Menu : \n");
    do
    {
        printf("Enter the choice from menu: ");
        scanf("%d",&choice);
        switch(choice){
            case(1): Enqueue();break;
            case(2): Dequeue();break;
            case(3): traverse();break;
            case(4): flag=0;break;
            default: printf("Invalid choice.");
        }
    } while(flag==1);
    
    return 0;
}
