#include<stdio.h>
#include<stdlib.h>

struct node {
    int info;
    struct node *prev;
    struct node *next;
};

struct node* start = NULL;

// Function to create a new node
struct node* create_node(int data) {
    struct node* ptr = (struct node*) malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("Overflow\n");
        return NULL;
    }
    ptr->prev = ptr->next = NULL;
    ptr->info = data;
    return ptr;
}

// Function to create the first node (initialize the list)
void create() {
    int data;
    struct node* ptr;
    printf("Enter the information to be stored in node: ");
    scanf("%d", &data);
    ptr = create_node(data);
    start = ptr;
}

// Function to insert a node at the beginning
void insert_Begin() {
    struct node* new;
    int data;
    printf("Enter the information to be stored in node (at beginning): ");
    scanf("%d", &data);
    new = create_node(data);
    if (new == NULL) { return; }
    new->next = start;
    if (start != NULL) {
        start->prev = new;
    }
    start = new;  // Update start to point to the new node
}

// Function to insert a node at the end
void insert_End() {
    struct node* new;
    int data;
    printf("Enter the information to be stored in node (at end): ");
    scanf("%d", &data);
    new = create_node(data);
    if (new == NULL) { return; }
    
    if (start == NULL) {
        start = new;
        return;
    }
    
    // Traverse to the last node
    struct node* temp = start;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->next = new;
    new->prev = temp;
}

// Function to insert a node after a specific node (based on info)
void insert_AfterData() {
    struct node* temp = start;
    struct node* new;
    int data, data_check;
    
    printf("Enter the information to be stored in node (after data): ");
    scanf("%d", &data);
    printf("Enter the data after which you want to add: ");
    scanf("%d", &data_check);
    
    // Traverse the list to find the node with info == data_check
    while (temp != NULL && temp->info != data_check) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Node with data %d not found!\n", data_check);
        return;
    }
    
    new = create_node(data);
    if (new == NULL) {
        return;
    }
    
    new->prev = temp;
    new->next = temp->next;
    
    if (temp->next != NULL) {
        temp->next->prev = new;  // Update the next node's prev pointer
    }
    
    temp->next = new;  // Insert the new node after temp
}

// Function to delete a node from the beginning
void delete_Begin() {
    struct node* tobedel = start;
    if (tobedel == NULL) {
        printf("Underflow\n");
        return;
    }
    
    start = tobedel->next;  // Move start to the next node
    if (start != NULL) {
        start->prev = NULL;  // Update the prev pointer of the new start
    }
    
    free(tobedel);  // Free the memory of the deleted node
}

// Function to delete a node from the end
void delete_End() {
    struct node* temp = start;
    if (temp == NULL) {
        printf("Underflow\n");
        return;
    }
    
    if (temp->next == NULL) {  // If there's only one node in the list
        free(temp);
        start = NULL;
        return;
    }
    
    // Traverse to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->prev->next = NULL;  // Update the second-last node's next pointer
    free(temp);  // Free the last node
}

// Function to traverse the list and print its contents
void traverse() {
    struct node* ptr;
    int nodeno = 0;
    for (ptr = start; ptr != NULL; ptr = ptr->next, nodeno++) {
        printf("Node no.%d has info = %d\n", nodeno + 1, ptr->info);
    }
}

int main() {
    int flag = 1, choice;
    printf("Menu:\n");
    printf("1. Create List\n");
    printf("2. Insert at Beginning\n");
    printf("3. Insert at End\n");
    printf("4. Insert After Data\n");
    printf("5. Delete from Beginning\n");
    printf("6. Delete from End\n");
    printf("7. Traverse the List\n");
    printf("8. Exit\n");
    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: { create(); break; }
            case 2: { insert_Begin(); break; }
            case 3: { insert_End(); break; }
            case 4: { insert_AfterData(); break; }
            case 5: { delete_Begin(); break; }
            case 6: { delete_End(); break; }
            case 7: { traverse(); break; }
            case 8: { flag = 0; break; }
            default: { printf("Invalid choice.\n"); break; }
        }
    } while (flag == 1);
    
    return 0;
}
