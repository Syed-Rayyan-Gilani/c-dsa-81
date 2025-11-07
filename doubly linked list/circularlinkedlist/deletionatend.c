#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *head = NULL, *temp, *newnode;
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

    // ---- delete last node ----
    if (head == NULL)
        printf("\nList is empty");
    
    else if (head->next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        struct node *prev = head;
        temp = head->next;
        while (temp->next != head)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = head; // second last node points to head
        free(temp);
    }

    // Display after deletion
    if (head != NULL)
    {
        printf("\nAfter deleting last node: ");
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
