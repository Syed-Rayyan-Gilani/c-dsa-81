#include <stdio.h>

void selectionSort(int A[], int n)
{
    int i, j, k, temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = k = i; j < n; j++)
        {
            if (A[j] < A[k])
                k = j;
        }

        // swap A[i] and A[k]
        temp = A[i];
        A[i] = A[k];
        A[k] = temp;
    }
}

int main()
{
    int n, i;
    int A[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);

    selectionSort(A, n);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", A[i]);

    return 0;
}
