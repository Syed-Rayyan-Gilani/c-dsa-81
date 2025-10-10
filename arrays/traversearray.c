#include <stdio.h>
int main()
{
    int array[100], n, i;
    printf("enter the size of an array : ");
    scanf("%d", &n);
    printf("print the elements of the array : \n");
    for (i = 0; i < n ; i++)

    {

        scanf("%d", &array[i]);
    }
    printf("the elements of the array are :\n");
    for (i = 0; i < n ; i++)
    {

        printf("%d  ",array[i]);
    }
    return 0;
}
