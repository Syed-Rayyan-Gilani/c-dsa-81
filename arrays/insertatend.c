#include <stdio.h>
int main()
{
    int a[100], x, n;
    printf("enter the size of an array :\n ");
    scanf("%d", &n);
    printf("enter %d elements :\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("enter the elements to insert at the end :\n ");
    scanf("%d", &x);
    a[n] = x;
    n++;
    printf("array after insertion :\n ");
    for (int i = 0; i < n; i++)
    {
        printf("%d", a[i]);
    }
    return 0;
}
