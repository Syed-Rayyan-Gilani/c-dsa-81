#include <stdio.h>
#include <stdlib.h>

/* -------- NODE STRUCTURE -------- */
struct Node
{
    int data;
    struct Node *lchild;
    struct Node *rchild;
};

struct Node *root = NULL;

/* -------- HEIGHT FUNCTION -------- */
int Height(struct Node *p)
{
    int x, y;
    if (p == NULL)
        return 0;

    x = Height(p->lchild);
    y = Height(p->rchild);

    return (x > y) ? x + 1 : y + 1;
}

/* -------- INORDER PREDECESSOR -------- */
struct Node *InPre(struct Node *p)
{
    while (p && p->rchild != NULL)
        p = p->rchild;
    return p;
}

/* -------- INORDER SUCCESSOR -------- */
struct Node *InSucc(struct Node *p)
{
    while (p && p->lchild != NULL)
        p = p->lchild;
    return p;
}

/* -------- INSERT (RECURSIVE) -------- */
struct Node *RInsert(struct Node *p, int key)
{
    if (p == NULL)
    {
        struct Node *t = (struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }

    if (key < p->data)
        p->lchild = RInsert(p->lchild, key);
    else if (key > p->data)
        p->rchild = RInsert(p->rchild, key);

    return p;
}

/* -------- DELETE NODE -------- */
struct Node *Delete(struct Node *p, int key)
{
    struct Node *q;

    if (p == NULL)
        return NULL;

    if (key < p->data)
        p->lchild = Delete(p->lchild, key);
    else if (key > p->data)
        p->rchild = Delete(p->rchild, key);
    else
    {
        // Leaf node
        if (p->lchild == NULL && p->rchild == NULL)
        {
            if (p == root)
                root = NULL;
            free(p);
            return NULL;
        }

        // Node with two children
        if (Height(p->lchild) > Height(p->rchild))
        {
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        }
        else
        {
            q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }
    return p;
}

/* -------- INORDER TRAVERSAL -------- */
void Inorder(struct Node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
}

/* -------- MAIN FUNCTION -------- */
int main()
{
    root = RInsert(root, 50);
    RInsert(root, 30);
    RInsert(root, 70);
    RInsert(root, 20);
    RInsert(root, 40);
    RInsert(root, 60);
    RInsert(root, 80);

    printf("Inorder Traversal: ");
    Inorder(root);

    printf("\n\nDeleting 50...\n");
    root = Delete(root, 50);

    printf("Inorder after deletion: ");
    Inorder(root);

    return 0;
}
