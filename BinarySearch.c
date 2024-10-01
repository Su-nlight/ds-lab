#include<stdio.h>

void main(){
    int i,ele,n;
    printf("Enter the size of array Required: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of sorted array: \n");
    for(i=0;i<n;i++){
        printf("Enter %d index element of array: ",i);
        scanf("%d", &arr[i]);
    }
    
    printf("Enter the element to be found: ");
    scanf("%d",&ele);

    /*binary sort algorithm*/
    int LB=0,UB=n-1,mid;
    for(mid=(LB+UB)/2; LB<=UB; mid=(LB+UB)/2){
        if(ele==arr[mid]){
            printf("Element %d found in array at index= %d",ele,mid);
            break;            
        }
        else if(ele>arr[mid]){
            LB=mid+1;
        }
        else{
            UB=mid-1;
        }
    }
}