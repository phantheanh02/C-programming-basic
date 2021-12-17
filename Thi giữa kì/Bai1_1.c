/* Task 1.1: Sử dụng mảng
   Phan The Anh
   MSSV: 20204941
*/
/* TESt CASE
  DANH SACH SAU KHI DOC
TheAnh 12346 anh@gmail.com
DuyDoanh 123456789 doanh@gmail.com
LeAnh 5655413 leanh@gmail.com
VanChung 453745254 VanChung@gmail.com
Huong 542745245 Huong@gmail.com
Haha 2626426 haha@gmail.com
Abc 012845747 abc@gmail.com
Xyz 987654 xyz@gmail.com
Noname 5151153 noname@gmail.com
Ngoc 0372011 Ngoc@gmail.com


   DANH SACH SAU KHI SAP XEP:
Abc 012845747 abc@gmail.com
DuyDoanh 012845747 doanh@gmail.com
Haha 012845747 haha@gmail.com
Huong 012845747 Huong@gmail.com
LeAnh 012845747 leanh@gmail.com
Ngoc 0372011 Ngoc@gmail.com
Noname 0372011 noname@gmail.com
TheAnh 0372011 anh@gmail.com
VanChung 0372011 VanChung@gmail.com
Xyz 0372011 xyz@gmail.com

Nhap 1 de tim kiem ten, nhap 0 de ket thuc: 1
Nhap ten can tim: Abc
Thong tin: Abc 012845747 abc@gmail.com

Nhap 1 de tim kiem ten, nhap 0 de ket thuc: 0
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

// Hàm đổi địa chỉ
void swap(DiaChi *a, DiaChi *b) {
   DiaChi tmp;
   strcpy(tmp.name, b->name);
   strcpy(b->name, a->name);
   strcpy(a->name, tmp.name);

   strcpy(tmp.phone, b->phone);
   strcpy(a->phone, tmp.phone);
   strcpy(b->phone, a->phone);

   strcpy(tmp.email, b->email);
   strcpy(b->email, a->email);
   strcpy(a->email, tmp.email); 
}

// Hàm sắp xếp tên tăng dần
void SapXep(DiaChi *address, int n) 
{
   for (int i = 0; i < n; i++) 
      for (int j = i + 1; j < n; j++) 
         if (strcmp((address + i)->name, (address + j)->name) > 0) 
            swap(address + i, address + j);
   
}

void TimKiemNhiPhan(DiaChi *a, char name[], int n) 
{
   int x = 0, y = n - 1;
   while (x <= y) 
   {
      int m = (x + y) / 2;
      int c = strcmp(name, (a + m)->name);
      if (c == 0) 
      {
         printf("Thong tin: %s %s %s\n", (a + m)->name, (a + m)->phone, (a + m)->email);
         return;
      }
      else if (c > 0)   x = m + 1;
      else  y = m - 1;
   }
   printf("KHONG TIM THAY!");
}

int main() 
{
   int n;
   char name[30], email[30], phone[20];

   // Doc du lieu tu file
   FILE *fptr = fopen("AddressBook.txt", "r+");
   fscanf(fptr, "%d", &n);
   for (int i = 0; i < n; i++) 
   {
      fscanf(fptr, "%s", name);
      fscanf(fptr, "%s", phone);
      fscanf(fptr, "%s", email);
      strcpy((DanhSach + i)->name, name);
      strcpy((DanhSach + i)->phone, phone);
      strcpy((DanhSach + i)->email, email);
   }
   // In du lieu sau khi doc file
   printf("\n  DANH SACH SAU KHI DOC\n");
   for (int i = 0; i < n; i++) 
      printf("%s %s %s\n", DanhSach[i].name, DanhSach[i].phone, DanhSach[i].email);

   // Sap xep theo ten
   SapXep(DanhSach, n);
   printf("\n\n   DANH SACH SAU KHI SAP XEP:\n");
   for (int i = 0; i < n; i++)
      printf("%s %s %s\n", DanhSach[i].name, DanhSach[i].phone, DanhSach[i].email);
   
   // Tìm kiếm nhị phân
   char tmp[30];
   int a;
   printf("\nNhap 1 de tim kiem ten, nhap 0 de ket thuc: ");
   scanf("%d",&a);
   while (a != 0)
   {
      printf("Nhap ten can tim: ");
      scanf("%s", tmp);
      TimKiemNhiPhan(DanhSach, tmp, n);
      printf("\nNhap 1 de tim kiem ten, nhap 0 de ket thuc: ");
      scanf("%d",&a);
   } 
   fclose(fptr);
}