#include <stdio.h>
int main()
{
    int array[100], n, x;
    printf("enter the size of the array : ");
    scanf("%d", &n);
    printf("enter %d elements : \n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    printf("enter the element to insert : \n");
    scanf("%d", &x);

    for (int i = n; i > 0; i--)
    {
        array[i] = array[i - 1];
    }
    array[0] = x;
    n++;
    printf("array after insertion : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    return 0;
}
