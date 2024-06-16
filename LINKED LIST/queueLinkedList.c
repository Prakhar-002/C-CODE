#include <stdio.h>
#include <stdlib.h>

struct node  {
      int data;
      struct node *next;
};

struct node *front=NULL;
struct node *rear = NULL;

void traversing(){
      printf("current queue values are...\n");
      struct node *ptr=front;
      while(ptr->next !=NULL){
            printf("%d\t",ptr->data);
            ptr=ptr->next;
      }
      printf("%d\n",ptr->data);
}

void createNode(){
      struct node *one=malloc(sizeof(struct node ));
      printf("Enter the data of first node ...\n");
      scanf("%d",&one->data);
      one->next=NULL;
      front=rear=one;
}

void enqueue(){
      if(rear==NULL){
            printf("linked list is empty ...create first node...\n");
            createNode();
      }
      struct node *two=malloc(sizeof(struct node ));
      printf("Enter the new node data ...\n");
      scanf("%d",&two->data);
      rear->next=two;
      rear=two;
      two->next =NULL;
}

void dequeue(){
      if(front==NULL){
            printf("queue is empty ...\n");
      }
      struct node *ptr=front;
      printf("popped data is :%d\n",ptr->data);
      front=front->next;
      free(ptr);
}

void peek(){
      printf("front value is %d\n",front->data);
}

void main(){
      printf("WELCOME to the world of queue by linked list ...\n");
      while(1){
            printf("\n");
            printf("Enter your choice...\n");
            int choice;
            printf("1 for create first node ...\n2 for enqueue one value in queue...\n3 for dequeue one value ...\n4 for peek ...\n5 for traversing ...\n6 for exit...\n-->");
            scanf("%d",&choice);
            switch (choice)
            {
            case 1:
                  createNode();
                  traversing();
                  break;
            case 2:
                  enqueue();
                  traversing();
                  break;
            case 3:
                  dequeue();
                  traversing();
                  break;
            case 4:
                  peek();
                  break;
            case 5:
                  traversing();
                  break;
            case 6:
                  printf("THANK-YOU !!!\n");
                  exit(0);
                  break;
            default:
                  printf("wrong choice...\n");
                  break;
            }
      }
}
