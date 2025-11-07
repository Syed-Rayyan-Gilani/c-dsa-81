#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *head = NULL, *temp = NULL, *newNode;
    int n, i, value;

    // Step 1: Create the linked list
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &value);
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode; // first node
            temp = head;
        }
        else
        {
            temp->next = newNode; // link next node
            temp = newNode;
        }
    }
    printf("\nLinked List created successfully.\n");
    printf("Elements are: ");

    temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    // Step 2: Insert new node at beginning
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter data to insert at beginning: ");
    scanf("%d", &newNode->data);
    newNode->next = head; // point to old head
    head = newNode;       // make new node the new head

    // Step 3: Print the final linked list
    temp = head;
    printf("\nLinked list after insertion at beginning: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}
