#include <stdio.h>
#include <stdlib.h>

// Khai báo cấu trúc chứa thông tin
typedef struct Address
{
    char name[30];
    char phone[15];
    char email[30];
} Address;

typedef struct node
{
    Address data;
    struct node *next;
} node;

typedef struct Queue
{
    node *front,*rear;
} Queue;

// Tạo một Queue rỗng
void Make_Null_Queue(Queue *Q)
{
    node *h;
    h=(node*)malloc(sizeof(node));
    h->next = NULL;
    Q->front = h;
    Q->rear = h;
    free(h);
}

// Đọc thông tin từ file
void ReadFile(FILE *p, Queue *Q)
{
    
}

void WriteFile(FILE *p, Queue *Q);
{

}

void main()
{
    Queue *Q;
    FILE *pr, *pw;
}