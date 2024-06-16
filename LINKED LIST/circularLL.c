#include <stdio.h>
#include <stdlib.h>

struct node  {
      int data;
      struct node *next;
};

struct node *head=NULL;

void traversing(){
      printf("current queue values are...\n");
      struct node *ptr=head;
      while(ptr->next !=head){
            printf("%d\t",ptr->data);
            ptr=ptr->next;
      }
      printf("%d\n",ptr->data);
}

void createNode(){
      struct node *one=malloc(sizeof(struct node ));
      printf("Enter the data of first node ...\n");
      scanf("%d",&one->data);
      head=one;
      one->next=head;
}

void insertBeg(){
      if(head==NULL){
            printf("node is not exist...creating first node ...\n");
            createNode();
      }
      struct node *two=malloc(sizeof(struct node));
      printf("Enter the data to insert at beg...\n ");
      scanf("%d",&two->data);
      struct node *ptr=head;
      while(ptr->next !=head){
            ptr=ptr->next;
      }
      two->next=head;
      head=two;
      ptr->next = head;
}

void insertEnd(){
      if(head==NULL){
            printf("node is not exist...creating first node ...\n");
            createNode();
      }
      struct node *three=malloc(sizeof(struct node));
      printf("Enter the data to insert at end...\n ");
      scanf("%d",&three->data);
      struct node*ptr=head;
      while (ptr->next!=head){
            ptr=ptr->next;
      }
      ptr->next=three;
      three->next=head;
}

void deleteBeg(){
      if(head==NULL){
            printf("node is not exist...deleting is not possible ...\n");
      }else{
            printf("deleting first node ...\n");
            struct node*ptr=head;
            while (ptr->next!=head){
                  ptr=ptr->next;
            }
            head=head->next;
            free(ptr->next);
            ptr->next = head;
      }
}

void deleteEnd(){
      if(head==NULL){
            printf("node is not exist...deleting is not possible ...\n");
      }else{
            struct node*ptr=head;
            while(ptr->next->next!=head){
                  ptr=ptr->next;
            }
            free(ptr->next);
            ptr->next=head;
      }
}

void main (){
      printf("WELCOME to the world of circular linked list...\n");
      int choice;
      printf("Enter your choice...\n");
      while(1){
            printf("1 for create first node...\n2 for insert at beg...\n3 for insert at end... \n4 for delete from beg...\n5 for delete from end... \n6 for just traversing...\n7 for exit\n--> ");
            scanf("%d",&choice);
            switch (choice){
            case 1:
                  createNode();
                  traversing();
                  break;
            case 2:
                  insertBeg();
                  traversing();
                  break;
            case 3:
                  insertEnd();
                  traversing();
                  break;
            case 4:
                  deleteBeg();
                  traversing();
                  break;
            case 5:
                  deleteEnd();
                  traversing();
                  break;
            case 6:
                  traversing();
                  break;
            case 7:
                  printf("Thank you !!!\n");
                  exit(0);
            default:
                  printf("wrong choice entered...\n");
                  break;
            }
      }
}