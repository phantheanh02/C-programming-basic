#include <stdio.h>

// Sắp xếp chèn
void insertion_sort(int list[], int n)
{
    int i, j;
    int next;
    for (i=1; i<n; i++) 
    {
        next= list[i];
        for (j=i-1;j>=0 && next< list[j];j--)
            list[j+1] = list[j];
        list[j+1] = next;
    }
}

// Sắp xếp chọn
void selection(int a[], int n)
{ 
    int i, j, min, tmp;
    for (i = 0; i < n-1; i++)
    {
        min = i;
        for (j = i+1; j <=n-1 ; j++) 
            if ( a[j] < a[min])
                min = j;
        tmp= a[i];
        a[i]= a[min];
        a[min] = tmp;
    } 
}

void bubble_sort(int list[], int n)
{
    int i,j,temp;
    for (i=0; i<n-1 ;i++)
    for (j=n-1; j>i; j--)
    {
        if ( list[j] < list[j-1] ) 
        {
            temp=list[j];
            list[j]=list[j-1];
            list[j-1]=temp;
        }
    }

}
void main()
{
    int list[10]={11,5,3,8,9,2,4,6,0,7};
    //selection(list,10);
    //insertion_sort(list,10);
    bubble_sort(list,10);
    int i;
    for ( i = 0; i < 10; i++)
        printf("%d ",list[i]);
    
}