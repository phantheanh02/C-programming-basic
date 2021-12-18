/* Task 1.4: Sử dụng stack
   Phan The Anh
   MSSV: 20204941
*/
#include <stdio.h>
#include <string.h>

// Khai báo cấu trúc
typedef struct DS 
{
   char name[30];
   char phone[20];
   char email[30];
} DiaChi;

// Khai báo mảng chứa 100 phần tử
DiaChi DanhSach[100];
int i=0,k=0;

// Ham pop
void pop()
{
    int j;
    DiaChi tmp;
    printf("\nKhanh hang bi loai: %s %s %s\n", DanhSach[0].name, DanhSach[0].phone, DanhSach[0].email);
    for (j=0; j<10; j++) 
        DanhSach[j]=DanhSach[j+1];
    i--;
}

// ham push
 void push()
{
    printf("Khach hang thu %d",k+1);
    printf("\nName: "); scanf("%s",DanhSach[i].name);
    printf("Phone: "); scanf("%s",DanhSach[i].phone);
    printf("Email: "); scanf("%s",DanhSach[i].email);
    i++;
    k++;
}
int main() 
{
    int n,j;
    char name[30], email[30], phone[20];
    printf("Nhap so khach hang; ");
    scanf("%d",&n);
    if (n<10 && n> 0) 
        for (j=0; j< n; j++) 
            push();
    else if (n> 10) 
    {
        for (j=0; j< 10; j++) 
            push();
        for (j=10; j<n; j++)
        {
            pop();
            push();
        }
    }
    else printf("Loi so luong!!");   
}