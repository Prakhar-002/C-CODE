#include <stdio.h>
#include <stdlib.h>

int top=-1;


void traversing(int arr[],int n){
      printf("your queue is ...\n");
      for(int i =0;i<n;i++){
            printf("%d\t",arr[i]);
      }
      printf("\n");
}

void enqueue(int arr[],int n){
      if(top==n-1){
            printf("queue is full...\n");
      }else{
            top++;
            printf("Enter the number at index %d\n",top);
            scanf("%d",&arr[top]);
      }
}

void enqueueAll(int arr[],int n){
      if(top==n-1){
            printf("queue...is full...\n");
      }else{
            while(top < n-1){
                  top++;
                  printf("Enter the number at index %d\n",top);
                  scanf("%d",&arr[top]);
            }
      }
}

void peek(int arr[],int n){
      printf("current pointer value is ...%d\n",arr[top]);
}

void shifting(int arr[],int n){
      for(int i=1;i<n;i++){
            arr[i-1]=arr[i];
            arr[i]=0;
      }
      traversing(arr,n);
}

void dequeue(int arr[],int n){
      if(top==-1){
            printf("queue is empty...\n ");
      }else{
            printf("number deleted is %d\n",arr[0]);
            arr[0]=0;
            shifting(arr,n);
      }
}

void dequeueAll(int arr[],int n){
      if(top==-1){
            printf("queue is empty...\n ");
      }else{
            for(int i=0;i<top+1;i++){
                  arr[i]=0;
            }
            traversing(arr,n);
      }
}

void main (){
      printf("WELCOME to the world of queue...\n");
      printf("Enter the length of queue...\n");
      int n;
      scanf("%d",&n);
      int arr[n];
      for (int i = 0; i < n; i++){
            arr[i]=0;
      }
      while (1){
            int choice;
            printf("Enter your choice...\n");
            printf("1 for enqueue one value in queue...\t2 for enqueue all remaining value in queue...\t3 for peek the current value \t4 for delete one value from queue...\t5 for delete all value from queue...\t6 for traversing your queue ...\t7 for exit ...\n-->");
            scanf("%d",&choice);
            switch (choice)
            {
            case 1:
                  enqueue(arr,n);
                  traversing(arr,n);
                  break;
            
            case 2:
                  enqueueAll(arr,n);
                  traversing(arr,n);
                  break;
            
            case 3:
                  peek(arr,n);
                  break;
            
            case 4:
                  dequeue(arr,n);
                  break;
            case 5:
                  dequeueAll(arr,n);                
                  break;
            
            case 6:
                  traversing(arr,n);
                  break;
            
            case 7:
                  printf("Thank you !!!\n");
                  exit(0);
            
            default:
                  printf("wrong choice ...\n");
                  break;
            }
      }
}