#include <stdio.h>
#include <stdlib.h>

int stack[1000], top = -1;

void push (int x)
{
    top++;
    stack[top]=x;
}

void pop()
{
    printf("%d",stack[top]);
    top--;  
}

void InPhanNguyen(int PhanNguyen, int b)
{
    if (PhanNguyen == 0) printf("0");   
    while (PhanNguyen != 0)
    {
        push(PhanNguyen%b);
        PhanNguyen=PhanNguyen/b;
    }
    while (top > -1)
        pop();
}

void InPhanDu (float PhanDu, int b)
{
    if (PhanDu != 0) printf(".");
    while (PhanDu != 0)
    {
        push((int)(PhanDu*2));
        pop();
        PhanDu= PhanDu*2 - (int)(PhanDu*2);
    }
    
}
int main()
{
    float n,PhanDu;
    int b, PhanNguyen;
    printf("Nhap he dem co so can chuyen: ");
    scanf("%d",&b);
    printf("Nhap so can chuyen: ");
    scanf("%f",&n);
    PhanNguyen=(int)n;
    PhanDu=  n- PhanNguyen;

    InPhanNguyen(PhanNguyen,b);
    InPhanDu(PhanDu,b);
    return 0;
}