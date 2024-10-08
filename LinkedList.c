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

void create(){
    int data;
    struct node* ptr;
    printf("Enter the information to be stored in node: ");
    scanf("%d",&data);
    ptr=create_node(data);
    start=ptr;
}

void insert_Begn(){
    struct node* new;
    int data;
    printf("Enter the information to be stored in node(at begenning): ");
    scanf("%d",&data);
    new = create_node(data);
    if(new==NULL){ return;}
    new->link=start;
    start=new;
}
void insert_End(){
    struct node* new;
    int data;
    printf("Enter the information to be stored in node(at End): ");
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
void insert_AfterData(){
    struct node* temp=start;
    struct node* new;
    int data;
    int data_check;
    printf("Enter the information to be stored in node(at index): ");
    scanf("%d",&data);
    printf("Enter the data after which you want to add: ");
    scanf("%d",&data_check);

    while(temp->info!=data_check && temp->link!=NULL){
        temp=temp->link;
    }
    if(temp==NULL){
        printf("Underflow");
        return;
    }
    new=create_node(data);
    new->link=temp->link;
    temp->link=new;
    return;
}

void delete_Begn(){
    struct node* tobedel=start;
    if(tobedel==NULL){
        printf("List is Empty.");
        return;
    }
    else{
        start=tobedel->link;
        free(tobedel);
    }
    
}

void delete_End(){
    struct node* temp=start;
    if(temp==NULL){
        printf("List is Empty.");
        return;
    }
    while(temp->link->link!=NULL){
        temp=temp->link;
    }
    if(temp->link->link==NULL){
        temp->link=NULL;
        free(temp->link);
        return;
    }
    printf("Error");
}
void traverse(){
    struct node* ptr;
    int nodeno=0;
    for(ptr=start; ptr!=NULL; ptr=ptr->link,nodeno++){
        printf("Node no.%d has info = %d \n", nodeno+1, ptr->info);
    }
}
int main(){
    create();
    insert_Begn();
    insert_End();
    insert_Begn();
    insert_End();
    traverse();
    insert_AfterData();
    traverse();
    return 0;
}
