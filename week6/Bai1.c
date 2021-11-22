// Chương trình tìm kiếm mảng bằng tìm kiếm tuần tự
#include <stdio.h>

int main()
{
    int i,a[11];
    for (i=0; i<11; i++) scanf("%d",&a[i]);
    for (i=0; i<10; i++) 
        if (a[10] == a[i])
        {
            printf("%d",i);
            return 0;
        }
    printf("0");
    return 0;
}