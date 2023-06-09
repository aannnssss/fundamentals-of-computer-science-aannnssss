#include <stdio.h>
#include <stdlib.h>

int main()
{
   int i;
   int mas[10];
   i=0;
   while (i<10)
   {
      mas[i]=7;
      printf("%d = %d\n",i,mas[i]);
      i+=1;
   }
   return 0;
}
