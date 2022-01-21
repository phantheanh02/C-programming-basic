#include <stdio.h>
#include <string.h>

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

void quicksort(DiaChi list[], int left, int right)
{
    int  i, j;
    char pivot[40];
    DiaChi *temp;
    if (left < right) 
    {
        i = left; j = right+1;
        strcpy(pivot,list[left].name);
        do 
        {
            do i++; while (strcmp(list[i].name,pivot) < 0);
            do j--; while (strcmp(list[j].name,pivot) > 0);
        if (i < j) SWAP(list[i], list[j], temp);
        } while (i < j);
        SWAP(list[left], list[j], temp);
        quicksort(list, left, j-1);
        quicksort(list, j+1, right);
    }
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
/*
   // Sap xep theo ten
   SapXep(DanhSach, n);
   printf("\n\n   DANH SACH SAU KHI SAP XEP:\n");
   for (int i = 0; i < n; i++)
      printf("%s %s %s\n", DanhSach[i].name, DanhSach[i].phone, DanhSach[i].email);
*/

    // Quick Sort
    quicksort(DanhSach,0,9);
   fclose(fptr);
}