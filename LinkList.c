#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int i;
typedef struct Node
{
    int value;
    struct Node *next;
} Node;

Node *head;

// Tạo node mới
Node *makeNode (int x)
{
    Node *q;
    q->value = x;
    q->next = NULL;
    return q;
}

// chèn 1 phần tử mới vào sau phần tử được trỏ bởi p
Node* insertAfter(Node *h, Node *p, int x)
{
    if (p==NULL) return h;
    Node *q = makeNode(x);
    if (h == NULL) return q;
    q->next = p->next;
    p->next = q;
    return h;
}

// chèn 1 phần tử mới vào trước phần tử được trỏ bởi p
Node *insertLast(Node *h, int x)
{
    Node* q = makeNode(x);
    if (h == NULL) return q;
    Node *p =h;
    while (p->next != NULL)
        p = p->next;
    p->next= q;
    return h;
}

// Tìm một phần tử có giá trị bằng X
Node* locate(Node *h, int x)
{
    Node *p=h;
    while ( p != NULL)
    {
        if (p->value == x) return p;
        p= p->next;
    }
    return NULL;
}

// XÓa một phần tử 
Node* Xoa(Node *h, Node *p)
{
    if (h == NULL || p == NULL) return h;
    if (h == p)
    {
        printf("\n Phan tu bi xoa: %d",h->value);
        h = h->next;
        return h;
    }
    else
    {
        h->next = Xoa(h->next,p);
        return h;
    }
}
int main()
{
    time_t t;
    int n;
    Node *head=NULL;
    Node *p;
    p=head;
    srand((unsigned) time(&t));

    // Thêm 10 phần tử vào list
    for (i=1; i<=10; i++) 
        insertAfter(head,p,rand() % 10);

    // Tìm phần tử
    printf("Nhap phan tu can tim: ");
    scanf("%d",&n);
    locate(head,n);

    //Xóa một phần tử
    Xoa(head,head->next);
        
}
