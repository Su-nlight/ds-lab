#include<stdio.h>

void main(){
    int i,n,ele;
    printf("Enter the size of array required: ");
    scanf("%d", &n);

    int arr[n];
    for(i=0;i<n;i++){
        printf("Enter the %d index of array: ", i);
        scanf("%d",&arr[i]);
    }

    printf("\nEnter the element to be searched: ");
    scanf("%d",&ele);

    for(i=0;i<n;i++){
        if(arr[i]==ele){
            printf("Element %d found at index= %d", ele, i);
            break;
        }
    }
}
