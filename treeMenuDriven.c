#include<stdio.h>
#include<stdlib.h>
struct Node{
      int data;
      struct Node *right;
      struct Node *left;
};

int idx = -1;

struct Node *tree(int arr[] ){
      idx++;
      if (arr[idx] == -1){ 
            return NULL;
      }
      struct Node *newNode = malloc(sizeof(struct Node));
      newNode->data = arr[idx];
      newNode->left = tree(arr);
      newNode->right = tree(arr);
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

// #define max (a , b)  (((a) > (b)) ? (a) : (b) );

int maxNo(int a , int b){
      if (a> b){
            return a;
      }else{
            return b;
      }
}


int nodeSum(struct Node * root){
      if (root == NULL){
            return 0;
      }
      
      int leftSum = nodeSum(root->left);
      int rightSum = nodeSum(root->right);

      return leftSum+rightSum + root->data;
}

int numberOfNodes(struct Node *root){
      if(root == NULL){
            return 0;
      }

      int lc = numberOfNodes(root->left);
      int rc = numberOfNodes(root->right);

      return lc + rc +1;
}

int height(struct Node *root){
      if (root == NULL){
            return 0;
      }

      int lh = height(root->left);
      int rh = height(root->right);

      return maxNo(lh , rh) +1;
}

struct Info{
      int diameter;
      int height;
};

struct Info* diameterOfTree(struct Node *root){
      if (root == NULL){
            struct Info *newNode = malloc(sizeof(struct Info));
            newNode->diameter = 0;
            newNode->height = 0;
            return newNode;
      }

      struct Info* leftInfo = diameterOfTree(root->left);
      struct Info* rightInfo = diameterOfTree(root->right);

      int selfDia = maxNo(maxNo(leftInfo->diameter , rightInfo->diameter) , leftInfo->height + rightInfo->height + 1);
      int selfHei = maxNo(leftInfo->height , rightInfo->diameter) +1;

      struct Info * returnNode = malloc(sizeof(struct Info));
      returnNode->diameter = selfDia ;
      returnNode->height = selfHei ;

      return returnNode;
}

struct Node *root;

void arrToTree(){
      printf("Enter the length of Tree array...\n");
            int n;
            scanf("%d",&n);
            int arr[n];
            printf("Enter the data of every node ( If child is not exist enter -1)\n");
            for (int i = 0; i < n; i++){
                  scanf("%d" , &arr[i]);
            }
            root= tree(arr);
            preOrder(root);
}

void main(){
      printf("WELCOME to the world of Tree...\n");
      while(1){
            printf("\nEnter your choice...\n");
            printf("1 for default Tree...\t2 for Input elements of array to convert it into Tree...\t3 for inOrder traversing...\t4 for preorder traversing...\t5 for postOrder traversing...\t6 for Number of nodes in Tree...\t 7 for Height of tree...\t8 for sum of data of nodes of tree...\t9 for Diameter of tree...\t10 for exit...\n-->");
            int choice;
            scanf("%d",&choice);
            switch (choice){
            case 1:
                  // int arr [] ={1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
                  printf("Default Tree...\n");
                  int arr[] ={1, 2, 3, -1, -1, -1, 4, 5, -1, -1, 6, -1, -1};
                  root= tree(arr);
                  preOrder(root);
                  break;
            case 2:
                  arrToTree();
                  break;
            case 3:
                  printf("InOrder traversing...\n");
                  inOrder(root);
                  break;
            case 4:
                  printf("PreOrder traversing...\n");
                  preOrder(root);
                  break;
            case 5:
                  printf("PostOrder traversing...\n");
                  postOrder(root);
                  break;
            case 6:
                  printf("Number of nodes in given Tree...\n");
                  printf("%d", numberOfNodes(root));
                  break;
            case 7:
                  printf("Height of given Tree...\n");
                  printf("%d", height(root));
                  break;
            case 8:
                  printf("Sum of nodes in given Tree...\n");
                  printf("%d\n", nodeSum(root));
                  break;
            case 9:
                  printf("Diameter of given Tree...\n");
                  struct Info * diaInfo = diameterOfTree(root);
                  printf("%d", diaInfo->diameter);
                  break;
            case 10:
                  printf("Thank you !!!\n");
                  exit(0);
            default:
                  printf("wrong choice !!!\n");
                  break;
            }
      }
}