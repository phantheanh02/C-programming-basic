#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char s1[100], s2[100], *ptr;
    printf("Please enter string s1: ");
    scanf("%s",s1);
    printf("Please enter string s2: ");
    scanf("%s",s2);
    ptr = (char *) malloc(200*sizeof(char));
    if (ptr == NULL)
    {
        printf("Problem memory!");
        return NULL;
    }
    ptr = strcat(s1,s2);
    printf("%s",ptr);
    free(ptr);
    return 0;
}