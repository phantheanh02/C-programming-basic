#include <stdio.h>
#include <stdlib.h>

int main (void) 
{
    FILE *fptr;
    int i,n,sum=0, *p;

    printf("Enter a list of numbers with the first is the size of list: \n");
    scanf("%d",&n);
    p = (int *)malloc(n*sizeof(int));
    for (i=n-1; i>=0; i--) 
    {
        scanf("%d",&p[i]);
        sum+=p[i];
    }

    fptr = fopen("out.txt","w+");
    if (fptr == NULL)
    {
        printf("Can't open!!! ");
        return 0;
    }
    
    for (i=0; i < n; i++)
        fprintf(fptr,"%d ",p[i]);
    fprintf(fptr,"%d",sum);
    free(p);
    fclose(fptr);
    return 0;
}