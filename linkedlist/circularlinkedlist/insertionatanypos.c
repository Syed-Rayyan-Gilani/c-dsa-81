#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int main()
{
    struct Node *head = NULL, *newnode, *temp;
    int n, data, pos;

    // --- create circular linked list ---
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        newnode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL)
        {
            head = newnode;
            head->next = head; // first node points to itself
        }
        else
        {
            temp = head;
            while (temp->next != head)
                temp = temp->next; // reach last node
            temp->next = newnode;
            newnode->next = head; // maintain circular link
        }
    }

    // --- insert at any position ---
    printf("\nEnter position to insert: ");
    scanf("%d", &pos);
    printf("Enter data to insert: ");
    scanf("%d", &data);

    newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;

    // Case 1: insert at beginning
    if (pos == 1)
    {
        temp = head;
        while (temp->next != head)
            temp = temp->next; // go to last node

        temp->next = newnode; // last node → newnode
        newnode->next = head; // newnode → old head
        head = newnode;       // update head
    }
    else
    {
        temp = head;
        for (int i = 1; i < pos - 1 && temp->next != head; i++)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }

    // --- display the circular linked list ---
    printf("\nCircular Linked List after insertion:\n");
    temp = head;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    return 0;
}
