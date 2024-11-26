#include<stdio.h>
#include<stdlib.h>

struct node
{
        int info;
        struct node *link;
};
struct node* start=NULL;

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
    if(start==NULL){
        start=new;
        return;
    }
    //else traverse to last 
    struct node* temp=start;
    while(temp->link!=NULL){
        temp=temp->link;
    }
    temp->link=new;
    return;
}

void Dequeue(){
    struct node* tobedel=start;
    if(tobedel==NULL){
        printf("Underflow");
        return;
    }
    else{
        start=tobedel->link;
        printf("Data in node is: %d",tobedel->info);
        free(tobedel);
    }

}

void traverse(){
    struct node* ptr;
    int nodeno=0;
    for(ptr=start; ptr!=NULL; ptr=ptr->link,nodeno++){
        printf("Node no.%d has info = %d \n", nodeno+1, ptr->info);
    }
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
