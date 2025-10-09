#include <stdio.h>
long long unsigned fibo(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibo(n - 1) + (n - 2);
}
int main()
{
    int n;
    printf("enter number of terms u want in a fibonacci series:");
    scanf("%d", &n);

    printf("fibonacci series:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", fibo( i));
    }
    return 0;
}