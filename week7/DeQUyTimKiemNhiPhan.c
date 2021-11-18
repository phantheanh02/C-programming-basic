#include <stdio.h>
#define NotFound (-1)
typedef int ElementType;

int dem=0;

int BinarySearch(ElementType A[ ], ElementType X, int L, int R ) 
{
    dem++;
    if (L>R)  return NotFound;
    int Mid = (L+R)/2;
    dem++;
    if (A[Mid] < X)  
        return BinarySearch(A,X,Mid+1,R);
    else if (A[Mid] > X) 
    {
        dem++;
        return BinarySearch(A,X,L,Mid-1);
    }
    else 
    {
        dem++;
        return Mid;
    }
}
main( )
{
    static int A[ ] = { 1, 3, 5, 7, 9, 13, 15 };
    int SizeofA = sizeof( A ) / sizeof( A[ 0 ] );
    int i;
    for( i = 0; i < 20; i++ )
        printf( "BinarySearch of %d returns %d\n",i, BinarySearch( A, i,0, SizeofA ) );
    printf("\nSo lan thuc hien %d",dem);
    return 0;
}