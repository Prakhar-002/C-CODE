#include <stdio.h>

void main(){
      int num;
      int m=1;
      printf("Enter the number...\n");
      scanf("%d",&num);
      while (num>0){
            printf("The %d place num is %d\n" , m ,num%10);
            num/=10;
            m*=10;
      }
}