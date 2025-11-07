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
    int n, i, value, pos, count = 0;

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

    // Step 2: Count the number of nodes
    temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    printf("\nTotal nodes: %d\n", count);

    // Step 3: Take position for insertion
    printf("Enter position to insert (1 to %d): ", count + 1);
    scanf("%d", &pos);

    // Step 4: Check if position is valid
    if (pos < 1 || pos > count + 1)
    {
        printf("Invalid position!\n");
        return 0;
    }

    // Step 5: Create new node
    newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data to insert: ");
    scanf("%d", &newNode->data);

    // Step 6: Perform insertion
    if (pos == 1)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        temp = head;
        for (i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Step 7: Display updated list
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
