/* Task 1.2 và 1.3: Sử dụng linklist và queue
   Phan Thế Anh
   MSSV: 20204941
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Khai báo cấu trúc
typedef struct DS 
{
   char name[30];
   char phone[20];
   char email[30];
   struct DS *next;
} DiaChi;

DiaChi *MakeNode (char name[], char phone[], char email[])
{
   DiaChi *tmp;
   tmp = (DiaChi *)malloc(sizeof(DiaChi));
   strcpy(tmp->name, name);
   strcpy(tmp->phone, phone);
   strcpy(tmp->email, email);
   tmp->next = NULL;
   return tmp;
}

void push(DiaChi *a, char name[], char phone[], char email[]) 
{
   while (a->next != NULL) 
      a = a->next;
   a->next = MakeNode(name,phone,email);
}

void pop(DiaChi *a)

{
   if (a != NULL) 
   {
      printf("%s -- %s -- %s\n", a->name, a->phone, a->email);
      pop(a=a->next);
   }
}
void TimKiem(DiaChi *address, char name[]) 
{
   DiaChi *a;
   a = address;
   while (a != NULL) 
      if (strcmp(a->name, name) == 0) 
      {
         printf("Thong tin: %s -- %s -- %s\n", a->name, a->phone, a->email);
         return;
      } else a = a->next;
   printf("KHONG TIM THAY");
}

int main() 
{
   int n;
   char name[30], email[30], phone[30];
   
   // Đọc dữ liệu từ file
   FILE *fptr = fopen("AddressBook.txt", "r+");
   DiaChi *head = NULL;
   head = (DiaChi *)malloc(sizeof(DiaChi));
   fscanf(fptr, "%d", &n);
   for (int i = 0; i < n; i++) 
   {
      fscanf(fptr, "%s", name);
      fscanf(fptr, "%s", phone);
      fscanf(fptr, "%s", email);
      push(head, name, phone, email);
   }
   
   
   DiaChi *h = head;
   printf("    DANH SACH THONG TIN"); 
   pop(h);
   // Tìm kiếm thông tin
   char tmp[30];
   int a;
   printf("\nNhap 1 de tim kiem ten, nhap 0 de ket thuc: ");
   scanf("%d",&a);
   while (a != 0)
   {
      printf("Nhap ten can tim: ");
      scanf("%s", tmp);
      TimKiem(head, tmp);
      printf("\nNhap 1 de tim kiem ten, nhap 0 de ket thuc: ");
      scanf("%d",&a);
   } 
   fclose(fptr);
}