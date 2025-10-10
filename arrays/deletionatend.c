#include <stdio.h>
int main()
{
    int a[100], n, i;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    // Deleting last element
    n--;  // Just reduce the size — no shifting needed

    printf("Array after deleting last element:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
