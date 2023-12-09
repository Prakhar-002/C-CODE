#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
      int data;
      int pri;
      struct node *next;
};
struct node * front=NULL;
struct node * rear=NULL;

void createNode(){
      printf("Queue does not exist creating first node\n");
      struct node *one =malloc(sizeof(struct node));
      printf("Enter the data of first node\n");
      scanf("%d",&one->data);
      printf("Enter the priority of first node\n");
      scanf("%d",&one->pri);
      one->next =NULL;
      front=one;
      rear =one;
}

void insertInPriorityQueue(){
      if(rear == NULL){
            createNode();
      }else{
           struct node *newNode =malloc(sizeof(struct node));
            printf("Enter the data of newNode \n");
            scanf("%d",&newNode->data);
            printf("Enter the priority of newNode \n");
            scanf("%d",&newNode->pri);
            if(newNode->pri <= front->pri){
                  newNode->next =front;
                  front =newNode;
            }else if(newNode->pri<rear->pri){
                  struct node *ptr =front;
                  while(ptr->next !=NULL){
                        if(newNode->pri >=ptr->pri){
                              newNode->next =ptr->next;
                              ptr->next =newNode;
                              break;
                        }
                        ptr =ptr->next;
                  }
            }else{
                  rear->next =newNode;
                  newNode->next =NULL;
            }
      }
}

void display(){
      if(front == NULL){
            printf("Queue is empty ...\n");
            return ;
      }
      struct node *ptr =front;
      printf("linked list data and priority\n");
      while (ptr->next !=NULL){
            printf("%d priority data is %d : \n",ptr->pri,ptr->data);
            ptr=ptr->next;
      }
      printf("%d priority data is %d : \n",ptr->pri,ptr->data);
      
}

void main(){
      printf("WELCOME to the world of priority queue !\n");
      while(1){
            printf("Enter your choice ...\n");
            printf("1 for create first node ...\n2 for insert value priority vise...\n3 for Display...\n4 for exit program...\n");
            int choice ;
            scanf("%d",&choice);
            switch (choice){
            case 1:
                  createNode();
                  display();
                  break;
            case 2:
                  insertInPriorityQueue();
                  display();
                  break;
            case 3:
                  display();
                  break;
            case 4:
                  printf("THANK YOU !!!\n");
                  exit(0);
                  break;
            default:
                  break;
            }
      }
}


