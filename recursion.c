#include <stdio.h>

//factorial...
int factorial(int n){
      if(n==0){
            return 1;
      }else{
            return n*factorial(n-1);
      }
}

// fibonacci...
int fibonacci(int n){
      if(n==0){
            return 0;
      }else if(n==1){
            return 1;
      }else{
            return(fibonacci(n-1)+fibonacci(n-2));
      }
}

void fibPrint(int n){
      printf("fibonacci up to %d terms are...\n",n);
      for(int i =0;i<n;i++){
            printf("%d\t",fibonacci(i));
      }
}

int sumN(int n){
      
}

void main (){
      int term;
      printf("Enter the value of terms of fibonacci you want...\n ");
      scanf("%d",&term);  
      fibPrint(term);
}