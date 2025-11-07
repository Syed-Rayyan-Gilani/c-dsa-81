#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head = NULL, *newnode, *temp;
    int n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
            temp = head;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }
    temp->next = head;  // make it circular

    // Insert at end
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter data to insert at end: ");
    scanf("%d", &newnode->data);

    temp = head;
    while (temp->next != head)
        temp = temp->next; // reach last node

    temp->next = newnode;
    newnode->next = head;

    // Display
    printf("\nAfter insertion at end: ");
    temp = head;
    while (temp->next != head) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);

    return 0;
}
