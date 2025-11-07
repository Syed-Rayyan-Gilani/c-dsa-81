#include <stdio.h>
#include <stdlib.h>

// Global head pointer
struct Node
{
    int data;
    struct Node *next, *prev;
} *head = NULL;

// Function to insert a node at any position
void insertAtPosition(int value, int pos)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = newNode->prev = NULL;

    // Insert at beginning
    if (pos == 1 || head == NULL)
    {
        newNode->next = head;
        if (head)
            head->prev = newNode;
        head = newNode;
        return;
    }

    // Insert at any other position
    struct Node *temp = head;
    for (int i = 1; i < pos - 1 && temp->next != NULL; i++)
        temp = temp->next;

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next)
        temp->next->prev = newNode;
    temp->next = newNode;
}

// Function to display the list
void display()
{
    struct Node *temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL)

    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main()
{
    int n, val, pos;
    struct Node *temp = NULL, *newNode;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Create initial list
    for (int i = 0; i < n; i++)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &newNode->data);
        newNode->next = newNode->prev = NULL;

        if (head == NULL)
            head = temp = newNode;
        else
        {
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
    }

    display();

    // Insert a new node at any position
    printf("\nEnter value to insert: ");
    scanf("%d", &val);
    printf("Enter position: ");
    scanf("%d", &pos);

    insertAtPosition(val, pos);

    display();

    return 0;
}
