#include <stdio.h>
void display(int arr[],int n){
      for(int i=0;i<n;i++){
            printf("%d\t",arr[i]);
      }
}

void insertionSort(int arr[], int n)
{
      int i, j, min;
      int arr1[n];
      for (int k = 0; k < n; k++)
      {
            arr1[k] = arr[k];
      }
      for (i = 1; i < n; i++)
      {
            min = arr1[i];
            j = i - 1;
            while ((min < arr1[j]) && (j >= 0))
            {
                  arr1[j + 1] = arr1[j];
                  j -= 1;
            }
            arr1[j + 1] = min;
      }
      for (int i = 0; i < n; i++)
      {
            printf("%d\t", arr1[i]);
      }
      // display(arr1,n);
}

void linear_search(int arr[], int n)
{
      int search,i ;
            printf("Enter element to be searched\n");
            scanf("%d", &search);
      for ( i = 0; i < n; i++)
      {
            if (arr[i] == search)
            {
                  printf("%d is present at location %d \n", search, i);
                  break;
            }
      }
      if (i == n)
            printf("%d isn't present in the array\n", search);
}
void delete ( int arr[],int n){
      int index,count;
      int in=1;
      printf("Enter the number of value you want to delete from array\n");
      scanf("%d",&count);
      for(int i=0;i<count;i++){
            printf("Enter the %d index\n",in);
            scanf("%d",&index);
            arr[index]=0;
            in++;
      }
      display(arr,n);
}
void update(int arr[],int n){
      int index,count,value;
      int in=1;
      printf("Enter the number of value you want to update from array\n");
      scanf("%d",&count);
      for(int i=0;i<count;i++){
            printf("Enter the %d index\n",in);
            scanf("%d",&index);
            printf("Enter the %d value\n",in);
            scanf("%d",&value);
            arr[index]=value;
            in++;
      }
      display(arr,n);

}

void main()
{
      int n, choice, i;
      printf("Enter no. of elements in an array\n");
      scanf("%d", &n);
      int arr[n];
      printf("Enter elements in an array\n");
      for (i = 0; i < n; i++)
      {
            scanf("%d", &arr[i]);
      }
      while(1){
            printf("Press 1 for Linear Search \nPress 2 for sorting\nPress 3 for display the array\nPress 4 for delete the element at any index\nPress 5 for the update an array at any index\nPress 6 to exit\n");
            scanf("%d", &choice);
            switch (choice){
            case 1:
                  linear_search(arr, n);
                  break;
            case 2:
                  insertionSort(arr, n);
                  break;
            case 3:
                  printf("Your entered array is :\n");
                  display(arr,n);
                  break;
            case 4:
                  delete(arr,n);
                  break;
            case 5:
                  update(arr,n);
                  break;
            case 6:
                  exit(0);
            default:
                  printf("Please enter the correct choice\n");
            }
      }
}