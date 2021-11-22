#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int x;
    struct node* next;
} node;

typedef node* position;
typedef struct 
{
    position front, rear;
} Queue;

// Tạo Queue rỗng
void Make_Null_Queue(Queue *Q)
{
    position h;
    h=(node*)malloc(sizeof(node));
    h->next = NULL;
    Q->front = h;
    Q->rear = h;
    free(h);
}

// Kiểm tra Queue rỗng
int EmptyQueue(Queue Q)
{
    return (Q.front == Q.rear);
}

// Thêm vào hàng đợi
void EnQueue(int x, Queue *Q)
{
    Q->rear->next=(node*)malloc(sizeof(node));
    Q->rear = Q->rear->next;
    Q->rear->x = x;
    Q->rear->next=NULL;
    printf("Element add: %d\n",Q->rear->x);
}

// Xóa Queue
void DeleteQueue(Queue *Q)
{
    if (!EmptyQueue(*Q)) 
    {
        printf("Element delete: %d",Q->front->x);
        Q->front = Q->front->next;
    }
    else printf("Queue empty");
}

void main()
{
    Queue *Q;
    Make_Null_Queue(Q);
    EnQueue(3,Q);
    DeleteQueue(Q);
}