#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
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
        newnode->prev = NULL;

        if (head == NULL)
        {
            head = newnode;
            newnode->next = head; // circular next
            newnode->prev = head; // circular prev
            temp = head;
        }
        else
        {
            newnode->prev = temp; // newnode's prev points to last node
            newnode->next = head; // newnode's next points to head
            temp->next = newnode; // last node's next points to newnode
            head->prev = newnode; // head's prev points to newnode
            temp = newnode;       // move temp to newnode
        }
    }

    // Display the list
    if (head != NULL)
    {
        printf("\nDoubly Circular Linked List: ");
        temp = head;
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("\n");
    }

    return 0;
}
