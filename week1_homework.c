#include <stdio.h>

void insertnumber(FILE *f1, FILE *f2)
{
    int c;
    int count='1';
    fputc(count,f2);
    fputc(' ',f2);
    while ( (c=fgetc(f1)) != EOF)
    {
       if (c == '\n')
       {
           fputc(c,f2);
           count++;
           fputc(count,f2);
           fputc(' ',f2);
       }
       else  fputc(c,f2);
    }
}
int main() 
{
    FILE *fptr1, *fptr2;
    fptr1=fopen("text.txt","r");
    fptr2=fopen("textnumber.txt","w");
    if (fptr1 == NULL) 
        printf("Cannot open file! ");
    else  insertnumber(fptr1,fptr2);
    fclose(fptr1);
    fclose(fptr2);
}
