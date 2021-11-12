#include<stdio.h>
int giaithua(int n)
{
    int i, gt=1;
    for(i=1;i<=n;i++)
    gt=gt*i;
    return gt;
}

void main(){
    int i, gt;
    for(i=1; i<=5; i++)
    {
        gt=giaithua(i);
        printf("%3d\n",gt);
    }
}
