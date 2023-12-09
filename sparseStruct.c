// sparse structure....
//If matrix contain zero more that non zero element then we store only the non zero element
#include <stdio.h>
#include <string.h>
#define max 50

struct sparse{
      int row,col,value;
}spMatrix[max];

void main (){
      int i,j,n,row,col;
      int k=0;
      printf("Enter matrix dimensions in row*column\n");
      scanf("%d%d",&row,&col);
      printf("Enter the number of non zero elements\n");
      scanf("%d",&n);
      for ( i = 0; i < n; i++){
            printf("Enter the row no.,col no.,value\n");
            scanf("%d%d%d",&spMatrix[i].row,&spMatrix[i].col,&spMatrix[i].value);
      }
      printf("Sparse matrix is :\n");
      for ( i = 0; i < row; i++){
            for (j = 0; j < col; j++){
                  if(spMatrix[k].row==i+1 &&spMatrix[k].col==j+1){
                        printf("%d\t",spMatrix[k].value);
                        k++;

                  }else{
                        printf("0\t");
                  }
            
            }
            printf("\n");
      }
}