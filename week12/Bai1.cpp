// Phan The Anh 20204941
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Address {
	char name[40];
	char email[40];
	char phone[40];
} Address;

Address DS[100];
int n = 0;

void KhoiTaoDuLieu() 
{
	FILE * fin = NULL;
	fin = fopen("danh_ba_in.dat", "wb+");
	char tmp[40];
	char * eof;
	if(fin == NULL)
	{
		printf("Loi mo file ghi du lieu\n");
		exit(-1);
	}
	printf("Nhap thong tin lien he cua 10 nguoi\n");
	for(int i = 0; i < 10; i++)
	{
		printf("Thong tin lien lac cua nguoi %d: \n", i + 1);
		fflush(stdin);
		printf("\tHo ten: ");
		fgets(tmp, 40, stdin);
		if(eof = strchr(tmp, '\n')) 
		{
			*eof = '\0';
		}
		strcpy(DS[i].name, tmp);
		fflush(stdin);
		printf("\tEmail: ");
		scanf("%40s", DS[i].email);
		fflush(stdin);
		printf("\tPhone: ");
		scanf("%11s", DS[i].phone);
	}
	fwrite(DS, sizeof(Address), 10, fin);
	fclose(fin);
}

void LayData()
{
	FILE * fin = NULL;
	fin = fopen("AddressBook.txt", "r+");
	if(fin == NULL)
	{
		printf("File khong ton tai");
		exit(-1);
	}
	fscanf(fin, "%d", &n);
	if(n == 0)
	{
		printf("Khong co lien he nao");
		exit(-1);
	}
	for(int i = 0; i < n; i++)
	{
		fscanf(fin, "%s", DS[i].name);	
		fscanf(fin, "%s", DS[i].phone);	
		fscanf(fin, "%s", DS[i].email);	
	}

}

void InDS()
{
	for(int i = 0; i < n; i++)
	{
		printf("Thong tin lien he nguoi thu %d \n", i +1);
		printf("\tHo ten: %s\n", DS[i].name);
		printf("\tPhone: %s\n", DS[i].phone);
		printf("\tEmail: %s\n", DS[i].email);
		printf("\n");
	}
}

void swap(Address *a, Address *b)
{
	Address temp;
	strcpy(temp.email, a->email);
	strcpy(temp.name, a->name);
	strcpy(temp.phone, a->phone);
	
	strcpy(a->phone, b->phone);
	strcpy(a->email, b->email);
	strcpy(a->name, b->name);
	
	strcpy(b->phone, temp.phone);
	strcpy(b->name, temp.name);
	strcpy(b->email, temp.email);
}

void quicksort(int first, int last){
   int i, j, pivot, temp;

   if(first<last)
   {
      pivot = first;
      i = first;
      j = last;

      while(i<j){
      	
         while((strcmp(DS[i].name, DS[pivot].name) < 0) && i<last)
            i++;
         while(strcmp(DS[j].name, DS[pivot].name) > 0)
            j--;
         if(i < j) {
         	swap(&DS[i], &DS[j]);
         }
      }
	  swap(&DS[pivot], &DS[j]);
      quicksort(first,j-1);
      quicksort(j+1,last);

   }
}

int KQ(int index)
{
	FILE * fout = NULL;
	fout = fopen("AddressBook.txt", "w+");
	if(fout == NULL)
	{
		printf("Loi mo file ghi\n");
		exit(-1);
	}
	
	fprintf(fout, "Ho ten: %s\nPhone: %s\nEmail: %s\n", DS[index].name, DS[index].phone, DS[index].email);
	fclose(fout);
	return 1;
}


int main()
{
	char tmp[40];
	LayData();
	InDS();
	quicksort(0, n - 1);
	printf("Sau khi sap xep\n");
	InDS();
	return 0;
}
