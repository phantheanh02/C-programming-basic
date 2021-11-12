#include <stdio.h>

#define Max 100
typedef struct Queue
{
    int s[Max];
    int front, rear;
} Queue;

// Khởi tạo Queue
void MakeNull_Queue (Queue *Q)
{
    Q->front= -1;
    Q->rear = -1;
}

// Kiểm ra Queue rỗng
int Empty_Queue (Queue Q)
{
    return Q.front == -1;
}

// Kiểm tra Queue đầy
int Full_Queue (Queue Q)
{
    return (Q.rear - Q.front + 1) == Max;
}

// Thêm vào hàng đợi
void EnQueue (int x, Queue *Q)
{
    if (!Full_Queue(*Q))
    {
        if (Empty_Queue(*Q)) Q->front=0;
        Q->rear++;
        Q->s[Q->rear] = x;
        printf("Element add: %d\n",Q->s[Q->rear]);
    }
    else printf("Queue full!!");
}

// Hủy Queue
void Delete_Queue(Queue *Q)
{
    if (!Empty_Queue(*Q))
    {
        Q->front++;
        if (Q->front > Q->rear) MakeNull_Queue(Q);
    }
    else printf("Queue empty!!!");
}

void main()
{
    Queue *Q;
    MakeNull_Queue(Q);
    EnQueue(4,Q);
    EnQueue(3,Q);
    Delete_Queue(Q);
}