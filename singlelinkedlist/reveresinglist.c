#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node
{
    int data;
    struct Node *next;
};

// Reverse function
void reverse(struct Node **head)
{
    struct Node *prev = NULL, *current = *head, *next = NULL;

    while (current != NULL)
    {
        next = current->next; // Save next node
        current->next = prev; // Reverse the link
        prev = current;       // Move prev one step ahead
        current = next;       // Move current one step ahead
    }

    *head = prev; // Update head to new first node
    printf("Linked list reversed successfully.\n");
}

// -----------------------------
// Main function
int main()
{
    struct Node *head = NULL, *newNode, *temp;
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Create linked list using user input
    for (int i = 1; i <= n; i++)
    {
        printf("Enter data for node %d: ", i);
        scanf("%d", &value);

        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL)
            head = newNode;
        else
        {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    // Display original list
    printf("\nOriginal Linked List: ");
    temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    // Reverse the list
    reverse(&head);

    // Display reversed list
    printf("\nReversed Linked List: ");
    temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}
