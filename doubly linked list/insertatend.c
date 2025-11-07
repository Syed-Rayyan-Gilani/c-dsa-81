#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

int main()
{
    struct Node *head = NULL, *temp = NULL, *newNode;
    int n, i, value;

    // Input number of nodes
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Create the doubly linked list
    for (i = 0; i < n; i++)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        newNode->prev = NULL;

        if (head == NULL)
        {
            // First node
            head = temp = newNode;
        }
        else
        {
            // Link at the end
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
    }

    // Display original list
    printf("\nOriginal Doubly Linked List: ");
    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    // Insert at end
    printf("\n\nEnter value to insert at end: ");
    scanf("%d", &value);

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL)
    {
        head = newNode; // List was empty
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next; // Move to last node

        temp->next = newNode; // Link at the end
        newNode->prev = temp;
    }

    // Display updated list
    printf("\nList after inserting at end: ");
    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
