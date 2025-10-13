#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int main()
{
    struct Node *head = NULL;
    struct Node *temp = NULL;
    struct Node *newNode = NULL;
    int n, i, value;

    // Step 1: Create the linked list
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    
    for (i = 0; i < n; i++)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));
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
            temp->next = newNode; // link new node
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

    // Step 2: Insert at the end
    newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("\nEnter data to insert at the end: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;

    // traverse to the last node
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;

    // Step 3: Display the updated linked list
    printf("\nUpdated Linked List: ");
    temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}
