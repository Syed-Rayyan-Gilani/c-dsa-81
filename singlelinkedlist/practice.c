#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
int main()
{
    struct node *head=NULL,*temp=NULL,*Newnode=NULL;
    int i, n,value;
    printf("enter no of nodes:");
    scanf("%d ",&n);

    for(i=0;i<n;i++)
    {
        Newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter data into node %d: ",i+1);
        scanf("%d",&value);
        Newnode->data=value;
        Newnode->next=NULL;

        if (head=NULL)
        {
            head=Newnode;
            head=temp;
        }
        else
        {
            temp->next=Newnode;
            temp=Newnode;
        }
    }
    printf("\nLinked List created successfully.\n");
    printf("Elements are: ");

    temp=head;
    while(temp!=NULL)
    {
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    return 0;
}