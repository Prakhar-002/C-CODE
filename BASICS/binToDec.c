#include <stdio.h>

void main(){
   int n, base = 1, b_val, rem, d_val;
   printf("enter a binary number ");
   scanf("%d", &n);
   b_val = n;
   while (n != 0)
   {
      rem = n % 10;
      d_val += rem * base;
      n /= 10;
      base *= 2;
   }
   printf("binary value is %d\n", b_val);
   printf("decimal value is %d\n", d_val);
}