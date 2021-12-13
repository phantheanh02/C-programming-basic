#include <stdio.h>

void adjust(int list[], int root, int n)
{
    int child, rootkey; 
    int temp;
    temp=list[root]; 
    rootkey=list[root];
    child=2*root;
    while (child <= n) 
    {
        if ( (child < n) && (list[child] < list[child+1]))
            child++;
        if (rootkey > list[child]) break;
        else 
        {
            list[child/2] = list[child];
            child *= 2;
        }
    }
    list[child/2] = temp;
}

void heapsort(int list[], int n)
{
    int i, j;
    int temp;
    for (i=n/2; i>0; i--) adjust(list, i, n);
    for (i=n-1; i>0; i--) 
    {
        temp=list[1];
        list[1] = list[i+1];
        list[i+1]=temp;
        adjust(list,1, i);
    }
}

void main()
{
    int i,n, list[100];
    printf("Nhap so phan tu: ");
    scanf("%d",&n);
    printf("Nhap key: ");
    for ( i = 1; i <= n; i++)
        scanf("%d",&list[i]);
    heapsort(list,11);
    for ( i = 1; i <= 10; i++)
        printf("%d ",list[i]); 
}