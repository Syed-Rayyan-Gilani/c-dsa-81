#include <stdio.h>
int TOH(int n,int a,int b,int c)
{
    if (n>0)
    {
        TOH(n-1,a,c,b);
        printf(" movefrom %d to %d\n",a,c);
        TOH(n-1,b,a,c);
    }
}
int main()
{
    int n,a=1,b=2,c=3;
    printf("enter no disks to interchange:");
    scanf("%d",&n);

    printf("\nSequence of moves:\n");
    TOH(n, a, b, c);
    return 0;

    
}