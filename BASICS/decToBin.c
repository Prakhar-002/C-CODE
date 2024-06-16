#include<stdio.h>
void main(){
    long long n ,d_val,b_val=0,base=1,rem;
    printf("enter decimal value");
    scanf("%d",&n);
    d_val=n;
    while (n!=0)
    {
        rem=n%2;
        b_val+=rem*base;
        n/=2;
        base*=10;
    }
    printf("decimal value is %d\n",d_val);
    printf("binary of thus value is %d\n",b_val);
}