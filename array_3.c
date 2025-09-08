#include <stdio.h>

int main()
{
    int arr[100], n, sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    printf("Sum: %d\n", sum);
    return 0;
}
