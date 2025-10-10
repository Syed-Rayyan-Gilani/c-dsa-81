#include <stdio.h>
int main()
{
    int a[100], index, n, x;
    printf("enter the size of array : \n");
    scanf("%d", &n);
    printf(" enter the %d elements :\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("enter the element to enter : \n");
    scanf("%d", &x);
    printf("enter position 0 to %d where u want to insert an element: ", n);
    scanf("%d", &index);
    for (int i = n; i > index; i--)
    {
        a[i] = a[i - 1];
    }
    a[index] = x;
    n++;
    printf("array after insertion : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
