/* Task 2
   Phan Thế Anh
   MsSV: 20204941
*/
/* TEST CASE
Nhap bieu thuc can tinh: 1 + 2*3/2
1   2   3 * 2 / + 
Ket qua gia tri bieu thuc = 4
*/
#include <stdio.h>

char stack[50];
int i = 0;
int StackGiaTri[50];
int giatri = 0;


void push(char a) 
{
   if (i == 49)
   {
      printf ("Stack day");
      return;
   }
   stack[i] = a;
   i++;
}

char pop() 
{
   if (i == 0) 
   {
      printf("Stack rong");
      return '\n';
   }
   return stack[--i];
}


int LayDau(char c) 
{
   if (c == '+' || c == '-')
      return 0;
   else
      return 1;
}

void pushNum(int x) 
{
   if (giatri == 49) 
   {
      printf("Stack day");
      return;
   }
   StackGiaTri[giatri] = x;
   giatri++;
}

int popNum() 
{
   if (giatri == 0) 
   {
      printf("Stack rong");
      return '\n';
   }
   return StackGiaTri[--giatri];
}
int main() 
{
   printf("Nhap bieu thuc can tinh: ");
   char c = getchar(),operator;
   int x, order;
   int KetQua = 0,tmp;
   do 
   {
      if ('0' <= c && c <= '9') 
      {
         pushNum((int)c - '0');
         putchar(c);
         putchar(' ');
      } 
      else
      {
         order = LayDau(c);
         while (i > 0 && LayDau(stack[i - 1]) >= order)
         {
            operator= pop();
            tmp = popNum();
            if (operator== '+')   tmp += popNum();
            if (operator== '-')   tmp = popNum() - tmp;
            if (operator== '*')   tmp *= popNum();
            if (operator== '/')   tmp = popNum() / tmp;
            pushNum(tmp);
            putchar(operator);
            putchar(' ');
         }
         push(c);
      }
      c = getchar();
   } while (c != '\n');
   while (i > 0) 
   {
      operator= pop();
      tmp = popNum();
      if (operator== '+')   tmp += popNum();
      if (operator== '-')   tmp = popNum() - tmp;
      if (operator== '*')   tmp *= popNum();
      if (operator== '/')   tmp = popNum() / tmp;
      pushNum(tmp);
      putchar(operator);
      putchar(' ');
   }
   KetQua = popNum();
   printf("\nKet qua gia tri bieu thuc = %d", KetQua);
}