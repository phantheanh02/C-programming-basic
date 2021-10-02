#include <stdio.h>
#include <string.h>

int i,j;

// hàm in ra các số khác nhau trong mảng
void  phantukhacnhau() 
{
    int  a[10];
    printf("please enter 10 numbers:\n");
    for (i=0 ; i<10; i++) scanf("%d",&a[i]);

    printf("Cac phan tu khac nhau: ");
    for (i=0; i<10; i++) 
        if (a[i] == 0) 
        {
            printf("%d ",a[i]);
            break;
        }
    for (i=0;i<10; i++) 
    if (a[i] !=  0  ) 
    {
        printf("%d ",a[i]);
        for (j=i+1; j<10; j++)
            if (a[j] == a[i]) a[j]=0;
        a[i]=0;
    }
}

// Hàm kiểm tra số lần xuất hiện của các kí tụ
void kitu() 
{
    char s[100], count=0;
    printf("Enter a line: ");
    fflush(stdin);
    gets(s);
    for (i=0; i<strlen(s); i++)
    if ( s[i] <= 'Z' && s[i] >= 'A' || s[i] <= 'z' && s[i] >= 'a') 
    {
        count=1;
        for (j=i+1; j<strlen(s); j++)
            if (s[j] == s[i]) 
            {
                count++;
                s[j]='0';
            }
         printf("The letter '%c' appears %d time(s).\n",s[i], count);
    }
    
}

// Kiểm tra hai mảng bằng nhau

int checkArray(int a1[], int a2[], int n) 
{
    for (i=0; i<n; i++) if (a1[i] != a2[i]) return 0;
    return 1;
}

// Thay thế kí tự

void replacechar()
{
    char s[100], char1, char2;
    scanf("%s %c %c",s,&char1,&char2);
    for (i = 0; i < strlen(s); i++)
       if (s[i] == char1) s[i] = char2;
    printf("%s",s); 
}

void split(float n ,int *ptr1, float *ptr2) 
{
    *ptr1 = (int)n;
    *ptr2 = n - (int)n;
}


int main(int argc, char argv[]) {
    //phantukhacnhau();
    //kitu();

/* Bài tập 3, kiểm tra 2 mảng bằng nhau hay không  
    int n1,n2, check;
    int a1[100], a2[100];
    printf("Nhap so phan tu cua mang 1: ");
    scanf("%d",&n1);
    for (i=0;i<n1;i++) scanf("%d",&a1[i]);
    printf("Nhap so phan tu cua mang 1: ");
    scanf("%d",&n2);
    for (i=0;i<n1;i++) scanf("%d",&a2[i]);
    if (n1 != n2) printf("%d",0);
    else   printf("%d",checkArray(a1,a2,n1));
*/

    //replacechar();

/*
    float n, tp;
    int pn;
    printf("please enter a number: ");
    scanf("%f",&n);
    split(n,&pn,&tp);
    printf("Integer : %d\nRemaining fraction is %f",pn,tp);
    return 0;
*/

// Bài tập tính diện tích
    float w,h;
    if (argc != 3) 
    {
        printf("Error!0");
        return 1;
    }
    w= atof(argv[1]);
    h= atof(argv[2]);
    printf("S=%f\nC=%f",w*h,2*(w+h));
    return 0;
}
