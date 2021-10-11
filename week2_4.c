#include <stdio.h>

void copy(FILE *p1, FILE *p2)
{
    int num;
    char s[100];
    while (!feof(p1))
    {
        num= fread(s,sizeof(char),100, p1);
        s[num*sizeof(char)] = '\0';
        fwrite(s,sizeof(char),num,p2);
    }
    
}
int main()
{
    FILE *f1, *f2;
    f1=fopen("lab1.txt","r");
    f2=fopen("lab1a.txt","w");
    if (f1 == NULL) 
    {
        printf("Can't open file!!");
        return 0;
    }
     if (f2 == NULL) 
    {
        printf("Can't open file!!");
        return 0;
    }
    copy(f1,f2);
    fclose(f1);
    fclose(f2);
    return 0;
}
