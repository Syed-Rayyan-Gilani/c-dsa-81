#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *head = NULL, *newnode, *temp;
    int n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL)
        {
            head = newnode;
            temp = head;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }
    temp->next = head; // Make the list circular

    // ---- delete first node ----
    if (head == NULL)
        printf("\nList is empty");
    else if (head->next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        temp = head;
        while (temp->next != head)
            temp = temp->next; // go to last node

        struct node *todelete = head;
        temp->next = head->next; // last node points to 2nd node
        head = head->next;       // head moves to next
        free(todelete);
    }

    // Display after deletion
    if (head != NULL)
    {
        printf("\nAfter deleting first node: ");
        temp = head;
        while (temp->next != head)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("%d\n", temp->data);
    }

    return 0;
}
