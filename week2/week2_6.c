

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum {SUCCESS, FAIL, MAX_ELEMENT = 20};

typedef struct phoneaddress 
{
    char name[20];
    char tel[11];
    char email[25];
} phoneaddress;

int main(void) 
{
    FILE *fp;
    int i,n, reval=SUCCESS;
    phoneaddress *phonearr;
    printf("Read from 2sd data to 3rd data \n");
    fp = fopen("phonebook.dat","r+b");
    if (fp == NULL)
    {
        printf("Can not open %s.\n", "phonebook.dat");
        reval= FAIL;
    }
    phonearr = (phoneaddress *)malloc(2 * sizeof(phoneaddress));
    if (phonearr == NULL)
    {
        printf("Memory allocation failed!\n");
        return FAIL;
    }

    if ( fseek(fp,1*sizeof(phoneaddress),SEEK_SET) != 0)
    {
        printf("Fseek failed!\n");
        return FAIL;
    }
    fread(phonearr, sizeof(phoneaddress), 2, fp);
    printf("\nDanh ba\n");
    for (i=0; i<2; i++)
{
    printf("\nName: %s\n",phonearr[i].name);
    printf("Tel: %s\n",phonearr[i].tel);
    printf("Email: %s\n",phonearr[i].email);
}
    strcpy(phonearr[1].name,"The Anh");
    strcpy(phonearr[1].tel,"0123456");
    strcpy(phonearr[1].email,"anh.pt@sis.hust.edu.vn");

    fseek(fp,1*sizeof(phoneaddress),SEEK_SET);
    fwrite(phonearr, sizeof(phoneaddress), 2, fp);
    fclose(fp);
    free(phonearr);
     
    return reval;
}