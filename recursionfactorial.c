#include <stdio.h>
long long unsigned fact(int n)
{
    if (n == 0 || n == 1)
    {
        return  1;
    }
    else
    {
        return (n)*fact(n - 1);
    }
}
int main()
{
    int n;
    printf("enter the number you want factorial of:");
    scanf("%d",&n);

    printf("the factorial of %d is %llu",n,fact(n));
    
return 0;
}