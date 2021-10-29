#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int a;
};

void main()
{
    struct node *top =NULL;
    int n,value;
    do 
    {
        do
        {
            printf("Nhap phan tu duoc them: ");
            scanf("%d",&value);
            top = push(top,value);
            printf("Nhan 1 de tiep tuc: ");
            scanf("%d",&n);
        } while ( n == 1);
        
        printf("Nhap 1 to pop mot phan tu");
        scanf("%d",&n);
        while (n == 1)
        {
            top = pop(top,&value);
            printf("Phan tu duoc pop: %d\n", value);
            printf("Nhap 1 de tiep tuc: ");
            scanf("%d",&n);
        }

        printf("Nhap 1 de tiep tuc: ");
        scanf("%d",&n);  
    } while ( n == 1) ;
}