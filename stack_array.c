#include <stdio.h>
#include <stdlib.h>

// using array stack implement...

int top = -1;

void pushWhole(int arr[], int n){
      if (top == n - 1){
            printf("Stack is full !!!\n");
      }
      else{
            while (top < n - 1){
                  top++;
                  int a;
                  printf("Enter data at index %d in stack...\n",top);
                  scanf("%d", &a);
                  arr[top] = a;
            }
      }
}

void popWhole(int arr[],int n){
      if(top==-1){
            printf("Stack is empty...\n");
      }else{
            while(top>=0){
                  printf("%d\t",arr[top]);
                  arr[top]=0;
                  top--;
            }
            printf("\n");
      }
}

void peek(int arr[],int n){
      if(top==-1){
            printf("Stack is not available...\n");
      }else{
            printf("%d\n",arr[top]);
      }
      
}


void push(int arr[],int n){
      if (top == n - 1){
            printf("Stack is full !!!\n");
      }
      else{
            top++;
            int a;
            printf("Enter data at index %d in stack...\n",top);
            scanf("%d", &a);
            arr[top] = a;
      }
}

void pop(int arr[],int n){
      if(top==-1){
            printf("Stack is empty\n");
      }else{
            printf("%d\n",arr[top]);
            arr[top]=0;
            top--;
      }

}

void printArr(int arr[],int n){
      printf("Stack values are...\n");
      for(int i=0;i<n;i++){
            printf("%d\t",arr[i]);
      }
      printf("\n");
}

void main(){
      printf("WELCOME to the world of stack...\n");
      int n;
      printf("Enter the length of stack...\n");
      scanf("%d",&n);
      int arr[n];
      for (int i = 0; i < n; i++){
            arr[i]=0;
      }
      while(1){
            printf("Enter your choice...\n");
            printf("1 for push 1 element...\t2 for pop 1 item...\t3 for peek the value...\t4 for push all value at a time...\t5 for pop all value at a time...\t6 for traversing...\t7 for exit...\n-->");
            int choice;
            scanf("%d",&choice);
            switch (choice)
            {
            case 1:
                  push(arr,n);
                  printArr(arr,n);
                  break;
            case 2:
                  pop(arr,n);
                  printArr(arr,n);
                  break;
            case 3:
                  peek(arr,n);
                  break;
            case 4:
                  pushWhole(arr,n);
                  printArr(arr,n);
                  break;
            case 5:
                  popWhole(arr,n);
                  printArr(arr,n);
                  break;
            case 6:
                  printArr(arr,n);
                  break;
            case 7:
                  printf("Thank you !!!\n");
                  exit(0);
            default:
                  printf("wrong choice !!!\n");
                  break;
            }
      }
      
}
