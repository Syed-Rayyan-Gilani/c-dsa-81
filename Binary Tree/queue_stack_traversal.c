#include <stdio.h>
#include <stdlib.h>

/* -------- NODE STRUCTURE -------- */
struct Node
{
    int data;
    struct Node *lchild;
    struct Node *rchild;
};

/* -------- STACK -------- */
struct Stack
{
    int size;
    int top;
    long int *S;
};

void createStack(struct Stack *st, int size)
{
    st->size = size;
    st->top = -1;
    st->S = (long int *)malloc(size * sizeof(long int));
}

void push(struct Stack *st, long int x)
{
    if (st->top != st->size - 1)
        st->S[++st->top] = x;
}

long int pop(struct Stack *st)
{
    if (st->top == -1)
        return 0;
    return st->S[st->top--];
}

/* -------- QUEUE -------- */
struct Queue
{
    int size;
    int front;
    int rear;
    struct Node **Q;
};

void createQueue(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (struct Node **)malloc(size * sizeof(struct Node *));
}

void enqueue(struct Queue *q, struct Node *x)
{
    q->Q[++q->rear] = x;
}

struct Node *dequeue(struct Queue *q)
{
    return q->Q[++q->front];
}

/* -------- TREE CREATION -------- */
struct Node *root = NULL;

void Treecreate()
{
    struct Node *p, *t;
    int x;
    struct Queue q;
    createQueue(&q, 100);

    printf("Enter root value: ");
    scanf("%d", &x);

    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;

    enqueue(&q, root);

    while (q.front != q.rear)
    {
        p = dequeue(&q);

        printf("Enter left child of %d (-1 for no child): ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }

        printf("Enter right child of %d (-1 for no child): ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}

/* -------- ITERATIVE PREORDER -------- */
void IPreorder(struct Node *p)
{
    struct Stack st;
    createStack(&st, 100);

    while (p != NULL || st.top != -1)
    {
        if (p != NULL)
        {
            printf("%d ", p->data);
            push(&st, (long int)p);
            p = p->lchild;
        }
        else
        {
            p = (struct Node *)pop(&st);
            p = p->rchild;
        }
    }
}

/* -------- ITERATIVE INORDER -------- */
void IInorder(struct Node *p)
{
    struct Stack st;
    createStack(&st, 100);

    while (p != NULL || st.top != -1)
    {
        if (p != NULL)
        {
            push(&st, (long int)p);
            p = p->lchild;
        }
        else
        {
            p = (struct Node *)pop(&st);
            printf("%d ", p->data);
            p = p->rchild;
        }
    }
}

/* -------- ITERATIVE POSTORDER (NEGATIVE MARKING) -------- */
void IPostorder(struct Node *p)
{
    struct Stack st;
    createStack(&st, 100);

    long int temp;

    while (p != NULL || st.top != -1)
    {
        if (p != NULL)
        {
            push(&st, (long int)p);
            p = p->lchild;
        }
        else
        {
            temp = pop(&st);

            if (temp > 0)
            {
                push(&st, -temp);
                p = ((struct Node *)temp)->rchild;
            }
            else
            {
                temp = -temp;
                printf("%d ", ((struct Node *)temp)->data);
                p = NULL;
            }
        }
    }
}

/* -------- MAIN -------- */
int main()
{
    Treecreate();

    printf("\nPreorder  : ");
    IPreorder(root);

    printf("\nInorder   : ");
    IInorder(root);

    printf("\nPostorder : ");
    IPostorder(root);

    return 0;
}
