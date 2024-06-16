#include <stdio.h>
#include <stdlib.h>

struct node  {
      int data;
      struct node *next;
};

struct node *top=NULL;

void traversing(){
      printf("current stack values are...\n");
      struct node *ptr=top;
      while(ptr->next!=NULL){
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
      top=one;
}

void push(){
      if(top==NULL){
            printf("linked list is empty ...create node first...\n");
            createNode();
      }
      struct node *two=malloc(sizeof(struct node ));
      printf("Enter the new node data ...\n");
      scanf("%d",&two->data);
      two->next=top;
      top=two;
}

void pop(){
      if(top==NULL){
            printf("stack is empty ...\n");
      }
      struct node *ptr=top;
      printf("popped data is :%d\n",ptr->data);
      top=top->next;
      free(ptr);
}

void popAll(){
      if(top==NULL){
            printf("stack is empty ...\n");
      }
      struct node *ptr=top;
      struct node *ptr1;
      while(ptr->next!=NULL){
            ptr1=ptr;
            ptr=ptr->next;
            free(ptr1);
      }
      free(ptr);
      top=NULL;
      printf("your created linked list is deleted...\n");

}

void peek(){
      printf("current value is %d\n",top->data);
}
void pushN(){
      int n;
      printf("Enter number of more linked list to be created...\n");
      scanf("%d",&n);
      for(int i=0;i<n;i++){
            push();
      }
}

void main(){
      printf("WELCOME to the world of stack by linked list ...\n");
      while(1){
            printf("\n");
            printf("Enter your choice...\n");
            int choice;
            printf("1 for create first node ...\t2 for push one value in stack...\t3 push n more values at a time...\t4 for pop one value ...\t5 for pop all value from stack...\t6 for peek ...\t7 for traversing ...\t8 for exit...\n-->");
            scanf("%d",&choice);
            switch (choice)
            {
            case 1:
                  createNode();
                  traversing();
                  break;
            case 2:
                  push();
                  traversing();
                  break;
            case 3:
                  pushN();
                  traversing();
                  break;
            case 4:
                  pop();
                  traversing();
                  break;
            case 5:
                  popAll();
                  break;
            case 6:
                  peek();
                  break;
            case 7:
                  traversing();
                  break;
            case 8:
                  printf("THANK-YOU !!!\n");
                  exit(0);
                  break;
            default:
                  printf("wrong choice...\n");
                  break;
            }
      }
}
