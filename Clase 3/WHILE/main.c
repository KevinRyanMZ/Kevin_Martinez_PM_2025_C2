#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cnt;
    cnt = -10;
    while (cnt <= 10)
    {
      if (cnt == 0) {cnt = 1;}

      printf("Valor cnt: %i\n", cnt);
      cnt ++;
    }
    printf("Acabo el programa, Gracias");
    return 0;
}
