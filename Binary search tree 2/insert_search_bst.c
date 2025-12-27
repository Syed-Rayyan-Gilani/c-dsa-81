#include <stdio.h>
#include <stdlib.h>

/* -------- Node Structure -------- */
struct Node
{
    int data;
    struct Node *lchild;
    struct Node *rchild;
};

struct Node *root = NULL;

/* -------- Insert Function (BST) -------- */
void Insert(int key)
{
    struct Node *t = root;
    struct Node *r = NULL, *p;

    if (root == NULL)
    {
        p = (struct Node *)malloc(sizeof(struct Node));
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
        return;
    }

    while (t != NULL)
    {
        r = t;
        if (key < t->data)
            t = t->lchild;
        else if (key > t->data)
            t = t->rchild;
        else
            return;   // duplicate not allowed
    }

    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = key;
    p->lchild = p->rchild = NULL;

    if (key < r->data)
        r->lchild = p;
    else
        r->rchild = p;
}

/* -------- Inorder Traversal -------- */
void Inorder(struct Node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
}

/* -------- Search in BST -------- */
struct Node *Search(int key)
{
    struct Node *t = root;

    while (t != NULL)
    {
        if (key == t->data)
            return t;
        else if (key < t->data)
            t = t->lchild;
        else
            t = t->rchild;
    }
    return NULL;
}

/* -------- MAIN FUNCTION -------- */
int main()
{
    Insert(50);
    Insert(30);
    Insert(70);
    Insert(20);
    Insert(40);
    Insert(60);
    Insert(80);

    printf("Inorder Traversal: ");
    Inorder(root);

    int key;
    printf("\nEnter value to search: ");
    scanf("%d", &key);

    if (Search(key))
        printf("Key found!\n");
    else
        printf("Key not found!\n");

    return 0;
}
