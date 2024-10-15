#include<stdio.h>
#include<stdlib.h>
#define MAX 50
int top=-1;
int stack[MAX];

void push(){
    if(top==MAX){
        printf("Overflow");
        return;
    }
    int data;
    printf("Enter the value to be pushed into the stack: ");
    scanf("%d",&data);
    top++;
    stack[top]=data;
    return;
}
void pop(){
    if(top==-1){
        printf("Underflow");
        return;
    }
    printf("Data stored is: %d",stack[top]);
    top--;
    printf("POPPED!");
    return;
}
void traverse(){
    printf("Stack is : \n");
    for(int i=0; i<=top; i++){
        printf(" %d,",stack[i]);
    }
}

void main(){
    int flag=1,choice;
    printf("Menu:- \n");
    do
    {
        printf("Enter the choice from menu: ");
        scanf("%d",&choice);
        switch(choice){
            case(1): {push();break;}
            case(2): {pop();break;}
            case(3): {traverse();break;}
            case(4): {flag=0;break;}
            default: {printf("Invalid choice.%d",choice);}
        }
    } while(flag);

}
