#include <stdio.h>

int main()
{
    char str[100];
    int i = 0;

    printf("Enter a string: ");
    scanf("%[^\n]", str); // reads input until newline

    while (str[i] != '\0')
    {
        i++;
    }

    printf("Length of the string = %d\n", i);

    return 0;
}
