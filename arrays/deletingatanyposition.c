#include <stdio.h>
int main()
{
    int a[100], n, index, i;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter the position to delete (0 to %d): ", n - 1);
    scanf("%d", &index);

    for (i = index; i < n - 1; i++)
    {
        a[i] = a[i + 1];
    }
    n--;

    printf("Array after deletion:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
