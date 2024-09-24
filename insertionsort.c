#include<stdio.h>

void main(){
    int i,j,n,key;
    printf("Enter the size of array required: ");
    scanf("%d", &n);

    int arr[n];
    for(i=0;i<n;i++){
        printf("Enter the %d index of array: ", i);
        scanf("%d",&arr[i]);
    }
    /*insertion sort algorithm*/
    for(i=1;i<n;i++){
        key=arr[i];
        for(j=i-1; j>=0 && arr[j]>key; j--){
                arr[j+1]=arr[j];
        }
        arr[j+1]=key;
    }

    printf("sorted array is: \n");
    for(i=0;i<n;i++){
        printf("\t %d", arr[i]);
    }
}
