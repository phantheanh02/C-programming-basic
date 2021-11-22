#include <stdio.h>

int n,a[100],i,j;
// Chuyển lên đầu
int searchFront(int k)
{
    int temp;
    for (i=0; i<n; i++)
    if (k == a[i])
    {
        if (i>0) 
        {
            temp = a[i];
            for (j=i; j>=0; j++) a[j] = a[j-1];
            a[0]=temp;
        }
        return i;
    }
    return -1;
}

// Đổi chỗ
int searchTranspose(int k)
{
    int temp;
    for (i=0; i<n; i++)
    if (k == a[i])
    {
        if (i>0) 
        {
            temp = a[i];
            a[i]=a[i-1];
            a[i-1]=temp;
        }
        return i;
    }
    return -1;
}
void main()
{
    int SoCanTim;
    printf("Nhap so phan tu: ");
    scanf("%d",&n);
    printf("Nhap %d phan tu: ",n);
    for (i=0; i<n; i++) scanf("%d",&a[i]);
    printf("Nhap so can tim: ");
    scanf("%d",&SoCanTim);
    printf("%d",searchTranspose(SoCanTim));
}