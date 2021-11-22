#include <stdio.h>
#include <stdlib.h>

typedef struct DNode
{
    int value;
    struct DNode *prev, *next;
} DNode;

DNode *first, *last;

// Tạo mới phần tử

DNode *makeNode(int v)
{
    DNode *p;
    p=(DNode*)malloc(sizeof(DNode));
    p->value=v;
    p->next=NULL;
    p->prev=NULL;
    return p;
}

void push_front(int x)
{
    DNode *p;
    p= makeNode(x);
    if (first == NULL)
    {
        first = p;
        last = p;
        return;
    }
    first->prev = p;
    p->next = first;
    first = p;
}

void push_back(int x)
{
    DNode *q = makeNode(x);
    if (first == NULL && last == NULL)
    {
        first = q;
        last = q;
        return;
    }
    last->next = q;
    q->prev = last;
    last = q;
}


void pop_front()
{
    if (first == NULL)
        return;
    first=first->next;
    first->prev=NULL;
}

void pop_back()
{
    if (first == NULL)
        return;
    last=last->prev;
    last->next = NULL;
}

int size()
{
    int dem=1;
    DNode *p;
    p = first;
    while (p != NULL) 
    {
        dem++;
        p=p->next;
    }
    return dem;
}

void clear()
{
    last=NULL;
    first=NULL;
}

void main()
{
    push_front(1);
    push_back(2);
    printf("Size of list: %d",size());
    pop_back();
    pop_front();
    clear();
}