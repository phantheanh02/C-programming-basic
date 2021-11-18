// Sử dụng tìm kiếm nhị phân 

#include <stdio.h>
#include <string.h>

typedef struct Address
{
    char name[30];
    char phoneNumber[30];
    char email[30];
} Address;

Address phonearr[100];

void DocDuLieu(FILE *fptr, int x)
{
    fread(phonearr,sizeof(Address),x,fptr);
}

void main()
{
    int n;
    printf("Nhap so phan tu danh ba: ");
    scanf("%d",&n);
    FILE *pi = fopen("danhba.txt","r");

}
