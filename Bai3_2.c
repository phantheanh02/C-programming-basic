#include <stdio.h>
#include <stdlib.h>

typedef struct Address
{
    char name[30];
    char phone[15];
    char email[30];
} Address;

typedef struct node
{
    Address data;
    struct Node *next;
} *node;

int main() 
{
    node *foot=NULL;
    return 0;
}
