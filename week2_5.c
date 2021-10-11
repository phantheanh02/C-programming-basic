#include <stdio.h>

typedef struct phoneaddress_t 
{
    char name[20];
    char tel[20];
    char email[25];
} phoneaddress;

int main() 
{
    FILE *fptr;
    phoneaddress phone[100];
    int i,n;
    printf("So thue bao can nhap: ");
    scanf("%d",&n);
    for (i = 0; i < n; i++)
    {
        printf("Thue bao 1\n");
        printf("Name: "); scanf("%s",phone[i].name);
        printf("Tel: "); scanf("%s",phone[i].tel);
        printf("Email: "); scanf("%s",phone[i].email);
    }
    fptr = fopen("phonebook.dat", "w+b");
    if (fptr == NULL) 
    {
        printf ("Can't open!!");
        return 0;
    }
    fwrite(phone, sizeof(phoneaddress), n ,fptr);
    fclose(fptr);

    fptr = fopen("phonebook.dat", "r+b");
    phoneaddress doc[100];
    printf("\nThong tin danh ba\n");
    fread(doc, sizeof(phoneaddress),n, fptr);
    for (i=0; i<n; i++)
    {
        printf("Name: %s\n",doc[i].name);
        printf("Tel: %s\n",doc[i].tel);
        printf("Email: %s\n",doc[i].email);
    }
    fclose(fptr);
    return 0;
}