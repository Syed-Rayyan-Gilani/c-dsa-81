#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int main()
{
    struct Node *head = NULL, *temp, *delNode, *newNode;
    int n, i, pos, count = 0;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Create linked list
    for (i = 0; i < n; i++)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter data: ");
        scanf("%d", &newNode->data);
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

    // Count nodes
    temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    printf("Enter position to delete (1 - %d): ", count);
    scanf("%d", &pos);

    if (pos < 1 || pos > count)
        printf("Invalid position!\n");
    else if (pos == 1)
    { // delete first node
        temp = head;
        head = head->next;
        free(temp);
    }
    else
    {
        temp = head;
        for (i = 1; i < pos - 1; i++)
            temp = temp->next;

        delNode = temp->next;
        temp->next = delNode->next;
        free(delNode);
    }

    printf("\nNode deleted from position %d.\n", pos);

    // Display list
    temp = head;
    printf("Updated list: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    return 0;
}
