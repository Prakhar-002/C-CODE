#include <stdio.h>
#include <stdlib.h>


void arrPrint(int arr[],int n){
      printf("Entered array is ...\n");
      for (int i = 0; i < n; i++){
            printf("%d ",arr[i]);
      }
      printf("\n");
      
}



void treeAsArray(){
      int n,count =0;
      printf("Enter the depth of array\n");
      scanf("%d",&n);
      int arr[n];
      printf("Enter the elements of array...\n");
      for (int i = 0; i < n; i++){
            scanf("%d",&arr[i]);
      }
      int tree[2*n+1];
      tree[0]=arr[0];
      int k=0;
      for (int i = 1; i < n; i+=2){
            tree[2*i] = arr[i];
            tree[2*i+1]= arr[i+1];
            printf("%d as parent has %d as left child and %d as a right child\n",arr[k],tree[2*i],tree[2*i+1]);
            k++;
      }  
      // printf("%d\n",k);
      while (k>1){
            count++;
            k/=2;
      }
      printf("Depth of tree is %d:\n",count);
      // arrPrint(tree,2*n+1);
}

void main(){
      printf("WE'll have a tree by an array\n");
      treeAsArray();
      
}