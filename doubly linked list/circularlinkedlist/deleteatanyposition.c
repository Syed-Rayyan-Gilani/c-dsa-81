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
    int n, i, pos;

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

    printf("Enter position to delete: ");
    scanf("%d", &pos);

    // ---- delete node at position ----
    if (head == NULL)
        printf("\nList is empty");
    else if (pos == 1)
    {
        // delete first node
        if (head->next == head)
        {
            free(head);
            head = NULL;
        }
        else
        {
            temp = head;
            while (temp->next != head)
                temp = temp->next;
            struct node *todelete = head;
            temp->next = head->next;
            head = head->next;
            free(todelete);
        }
    }
    else
    {
        struct node *curr = head;
        for (i = 1; i < pos - 1 && curr->next != head; i++)
            curr = curr->next;

        struct node *todelete = curr->next;
        if (todelete != head)
        {
            curr->next = todelete->next;
            free(todelete);
        }
        else
        {
            printf("Invalid position\n");
        }
    }

    // Display after deletion
    if (head != NULL)
    {
        printf("\nAfter deleting node at position %d: ", pos);
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
