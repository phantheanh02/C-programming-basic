#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
char stack[100];
int top= 0;
int isEmpty()
{
    if (top == 0) return 1;
    else return 0;
}

int isFull()
{
    if (top == MAX) return 1;
    else return 0;
}

void push(char value)
{
    if (!isFull())
    {
        top++;
        stack[top]=value;
    }
    else printf("Stack full!!");
}

char pop()
{
    char value;
    if (!isEmpty)
    {
        value=stack[top];
        top--;
        return value;
    }
    else ("Stack empty");
}

int main()
{
    char a[100];
    printf("Nhap chuoi can doi\n");
    scanf("%s",a);
    int i;
    for (i=0; i<=strlen(a); i++)
        push(a[i]);
    while (!isEmpty())
    {
        printf("%c",pop());
    }
    return 0;
}