/* Phan Thế Anh - 20204941 */
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

int main() {
    //phantukhacnhau();
    kitu();
    return 0;
}
