#include<stdio.h>
#include<stdlib.h>
struct Node{
      int data;
      struct Node *right;
      struct Node *left;
};

int idx = -1;

struct Node *tree(int arr[] , int n){
      if (idx == n-1){
            return NULL;
      }
      idx++;

      struct Node *newNode = malloc(sizeof(struct Node));
      newNode->data = arr[idx];
      newNode->left = tree(arr , n);
      newNode->right = tree(arr, n);
      return newNode;
} 

void inOrder(struct Node *root ){
      if(root == NULL){
            return;
      }

      inOrder(root->left);
      printf("%d\t",root->data);
      inOrder(root->right);
}

void preOrder(struct Node *root ){
      if(root == NULL){
            return;
      }

      printf("%d\t",root->data);
      preOrder(root->left);
      preOrder(root->right);
}

void postOrder(struct Node *root ){
      if(root == NULL){
            return;
      }

      postOrder(root->left);
      postOrder(root->right);
      printf("%d\t",root->data);
}


void main(){
      int arr [] ={4,5,8,3,7,9,10};
      // struct Node *root= tree(arr,7);
      struct Node * root = malloc(sizeof(struct Node));
      root->data = 10;
      root->left = malloc(sizeof(struct Node));
      root->left->data = 12;
      root->left->left = NULL;
      root->left->right = NULL;
      root->right = malloc(sizeof(struct Node));
      root->right->data = 15;
      root->right->left = NULL;
      root->right->right = NULL;
      printf("inOrder...\n");
      inOrder(root);
      printf("\npreOrder...\n");
      preOrder(root);
      printf("\npostOrder...\n");
      postOrder(root);
}