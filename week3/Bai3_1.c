#include <stdio.h>
#include <stdlib.h>

int i;
// Tạo struct
typedef struct Address
{
    char name[30];
    char phone[15];
    char email[30];
} Address;

// Tạo node
typedef struct node
{
    Address data;
    struct Node *next;
} node;

// Khởi tạo 1 danh sách liên kết
node *CreateList() 
{
    i=1;
    int check;
    printf("Nhap 1 de tiep tuc, nhap 0 de ket thuc: ");
    scanf("%d",&check);
    node *value,*head;
    while (check) {
        if (head == NULL)
        {
            head= (node*)malloc(sizeof(node));
            value=head;
        }
        else 
        {
            value = head;
            while (value->next != NULL) value=value->next;
            value->next = (node*)malloc(sizeof(node));
            value = value->next;
        }
            printf("Nhap thong tin cua nguoi thu %d\n",++i);
            printf("Ten: ");
            scanf("%s",value->data.name);
            printf("SĐT: ");
            scanf("%s",value->data.phone);
            printf("Email: ");
            scanf("%s",value->data.email); 
            value->next=NULL;
            printf("Nhap 1 de tiep tuc, nhap 0 de ket thuc: ");
            scanf("%d",&check);
    }
    return head;
}

// In thông tin ra màn hình
void InThongTin(node *head) {
    printf("DANH SACH THONG TIN\n");
    node *p;
    p=head->next;
    while (p != NULL)
    {
       printf("Name: %s -- SDT: %s -- Email: %s\n",p->data.name,p->data.phone,p->data.email);
       p= p->next;
    }
    
}

// Chèn 1 phần tử vào đầu ds
node* inser(node *h, Address x)
{
    node *p;
    p->data = x;
    p->next=h->next;
    h=p;
    return h;
}

// Xóa một node
node* delete(node *h)
{
    if (h==NULL) printf("List empty");
    else    h = h->next;
    return h;
}
int main()
{
    node *head=NULL;
    head = CreateList();
    InThongTin(head);
    return 0;
}