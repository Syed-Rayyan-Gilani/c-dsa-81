//WAP to display a string
#include<stdio.h>
int main()
{
    char str[100];
    int i;
    printf("enter your string : ");
    scanf("%s",&str);
    printf("the displayed string : ");
    for(i=0;str[i]!='\0';i++)
    {
        printf("%c",str[i]);
    }
    return 0;

  
    printf("displayed string is : %s",str);
    return 0;

}
