#include <stdio.h>
long long unsigned fact(int n)
{
    if (n==0 || n==1)
    return 1;
    else 
    return fact(n-1)*n;
}
int main()
{
    int number;
    printf("enter the no:");
    scanf("%d",&number);
    number=fact(number);
    printf("the factorial is %d",number);
    return 0;
}