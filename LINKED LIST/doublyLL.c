#include <stdio.h>
#include <stdlib.h>

struct node{
      int data;
      struct node *next;
      struct node* prev ;
};

struct node *head=NULL;

void traversing(){
      struct node*ptr=head;
      printf("linked list is ...\n");
      while(ptr->next!=NULL){
            printf("%d\t",ptr->data);
            ptr=ptr->next;
      }
      printf("%d\n",ptr->data);
}

void createNode(){
      struct node *one=malloc(sizeof(struct node));
      printf("Enter the first node value\n");
      scanf("%d",&one->data);
      head=one;
      one->next=NULL;
      one->prev = NULL;
}

void insertBeg(){
      if(head==NULL){
            printf("node is not exist...creating first node ...\n");
            createNode();
      }
      struct node *two=malloc(sizeof(struct node));
      printf("Enter the data to insert at beg...\n ");
      scanf("%d",&two->data);
      two->next = head;
      two->prev =NULL;
      head->prev = two;
      head =two;
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
      while (ptr->next!=NULL){
            ptr=ptr->next;
      }
      ptr->next=three;
      three->next=NULL;
      three->prev =ptr;
}

void insertAnyPos(){
      if(head==NULL){
            printf("node is not exist...creating first node ...\n");
            createNode();
      }
      struct node *four=malloc(sizeof(struct node));
      printf("Enter the data to insert at any position...\n ");
      scanf("%d",&four->data);
      struct node*ptr=head;
      printf("Enter the data after which you want to enter the data...\n");
      int a;
      scanf("%d",&a);
      while(ptr->next!=NULL){
            if(ptr->data==a){
                  four->next=ptr->next;
                  ptr->next->prev = four;
                  ptr->next=four;
                  four->prev = ptr;
                  break;
            }
            ptr=ptr->next;
      }
      if(ptr->next==NULL&&ptr->data!=a){
            printf("given value is not found !!!\n");
      }
}

void deleteBeg(){
      if(head==NULL){
            printf("node is not exist...deleting is not possible ...\n");
      }else{
            printf("deleting first node ...\n");
            struct node*ptr=head;
            head=head->next;
            head->prev =NULL;
            free(ptr);
      }
}

void deleteEnd(){
      if(head==NULL){
            printf("node is not exist...deleting is not possible ...\n");
      }else{
            struct node*ptr=head;
            while(ptr->next->next!=NULL){
                  ptr=ptr->next;
            }
            free(ptr->next);
            ptr->next=NULL;
      }
}

void deleteAnyPos(){
      if(head==NULL){
            printf("node is not exist...deleting is not possible ...\n");
      }else{
            struct node*ptr=head;
            struct node*ptr1;
            printf("Enter the data of node to delete that node...\n");
            int a;
            scanf("%d",&a);
            while(ptr->next!=NULL){
                  if(ptr->data==a){
                        ptr1->next=ptr->next;
                        ptr->next->prev = ptr1;
                        free(ptr);
                        break;

                  }
                  ptr1=ptr;
                  ptr=ptr->next;
                  if(ptr->next==NULL){
                        if(ptr->data!=a){
                              printf("given value is not found !!!\n");
                        }
                  }
            }
      }
      
}

void main (){
      printf("WELCOME to the world of circular linked list...\n");
      int choice;
      printf("Enter your choice...\n");
      while(1){
            printf("1 for create first node...\n2 for insert at beg...\n3 for insert at end...\n4 for insert at any position... \n5 for delete from beg...\n6 for delete from end...\n7 for delete at position... \n8 for just traversing...\n9 for exit\n--> ");
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
                  insertAnyPos();
                  traversing();
                  break;
            case 5:
                  deleteBeg();
                  traversing();
                  break;
            case 6:
                  deleteEnd();
                  traversing();
                  break;
            case 7:
                  deleteAnyPos();
                  traversing();
                  break;
            case 8:
                  traversing();
                  break;
            case 9:
                  printf("Thank you !!!\n");
                  exit(0);
            default:
                  printf("wrong choice entered...\n");
                  break;
            }
      }
}
