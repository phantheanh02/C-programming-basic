//đoc 10 địa chỉ từ flie và ghi dữ liệu cần tìm vào một file khác

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Address
{
    char name[30];
    char NumberPhone[15];
    char email[30];
} Address;

typedef struct DoubleList
{
    Address data;
    struct DoubleList *next, *prev;
} DoubleList;

DoubleList *MakeNode(Address value)
{
    DoubleList *p;
    p=(DoubleList*)malloc(sizeof(DoubleList));
    p->data=value;
    p->next=p->prev=NULL;
    return p;
}
int dem=0;
void FindInfo(FILE *f1, DoubleList *h, char s[])
{
    DoubleList *p;
    Address a[100];
    p=h->next;
    while (!p->next)
    {
        if (strcmp(p->data.name,s))
        {
            a[dem]=p->data;
            dem++;
        }
        fwrite(a,sizeof(Address),dem,f1);    
    }
}
void main()
{
    int i;
    char s[30];
    Address a[100], doc[100];
    DoubleList *head=NULL, *p,*q;
    FILE *fi, *fo;
    fi=fopen("telephon.dat","r");
    fo=fopen("telephoneout.dat","w");
    if (fi == NULL) printf("File erro!!");
    else 
    {
       fread(a, sizeof(Address),10, fi);
       head->next=p;
       p->data=a[0];
       p->prev=head;
       for (i=1; i<10; i++)
       {
            q=MakeNode(a[i]);
            p->next=q;
            q->prev=p;
            p=q;
       } 
       printf("Enter name need be found: ");
       scanf("%s",s);   
       FindInfo(fo,head,s);
       fread(doc, sizeof(Address),10, fo);
        for (i=0; i<10; i++)
        {
            printf("Name: %s\n",doc[i].name);
            printf("Tel: %s\n",doc[i].NumberPhone);
            printf("Email: %s\n",doc[i].email);
        }
    }
    fclose(fi);
    fclose(fo);
}