#include <stdio.h>

void linear_search(int arr[],int n,int search){
    int i;
    for(i=0;i<n;i++){
        if(arr[i] == search){
            printf("%d is present at location %d \n", search,i);
            break;
        }   
    }
    if(i==n)
    printf("%d isn't present in the array\n", search);
}

void binary_search(int arr[], int n, int search){
    int i,first,last,middle;
    first = 0;
    last = n-1;
    middle = (first+last)/2;
    while(first<=last){
        if(arr[middle]<search)
        first = middle+1;
        else if(arr[middle]==search)
        {
            printf("%d found at location %d \n", search,middle);
            break;
        }
        else
        last = middle-1;
        middle=(first+last)/2;
    }
    if(first>last)
    printf("\nNot found! %d isn't present in the list \n", search);
}
void bubbleSort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void main(){
    int n, choice, i,search;
    printf("Enter no. of elements in an array\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements in an array\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter element to be searched\n");
    scanf("%d",& search);
    printf("Press 1 for Linear Search \nPress 2 for Binary Search\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        linear_search(arr, n, search);
        break;
    case 2:
        bubbleSort(arr,n);
        printf("Sorted Array is\n");
        for(i=0;i<n;i++){
            printf("%d \t", arr[i]);
        }
        printf("\n");
        binary_search(arr, n,search);
        break;
    default:
        printf("Please enter the correct choice\n");
    }
}