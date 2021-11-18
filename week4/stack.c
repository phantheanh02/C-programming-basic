#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int a;
};
int stack[1000];
int top=-1;
void push(int x)
{
    top++;
    stack[top]=x;
}

void pop()
{
    top--;
    printf("Phan tu duoc pop: %d\n", stack[top]);
}
void main()
{
    int n,value;
do 
{
    printf("Nhap 1 de push, 2 de pop, 3 de ket thuc:\n");
    scanf("%d",&n);
    if ( n == 1);
    {
        printf("Nhap phan tu duoc them: ");
        scanf("%d",&value);
        push(value);
    } 
    if (n == 2)
        pop(top);
}  while (n != 3);

}