#include <stdio.h>

int main()
{
    int n;

    // Step 1: Take size input
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n]; // declare array

    // Step 2: Take array input
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Step 3: Reverse the array
    for (int i = 0; i < n / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }

    // Step 4: Print reversed array
    printf("Reversed array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
