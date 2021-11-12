#include <stdio.h>
#include <string.h>

void main()
{
    FILE *ptr;
    int  i;
    char s[30], check[30];
    ptr=fopen("text.txt","r+");
    // fprintf(ptr,"hahaha\n");
    // fprintf(ptr,"kakaka\n");
    // fprintf(ptr,"bababa\n");
    // fprintf(ptr,"tatata");
    printf("Nhap tu can tim: ");
    scanf("%s",&s);
    while (fgets(check,30,ptr)!= NULL)
    {
        if (strstr(check,s))
            printf("%s",check);
    }
    fclose(ptr);
}