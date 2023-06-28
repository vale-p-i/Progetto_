#include <stdio.h>
#include "operation.h"

int main()
{
  int num=0;

  while(!num){
    printf("Inserire: \n1 Per risolvere un'equazione congruenziale;\n2 Per risolvere un sistema di equazioni congruenziali;\n");
    scanf("%d", &num);

    if(num==1) {
      eq_cong();
      return 0;
    }else if(num==2) {
      sistem();
      return 0;
    }else {
      num=0;
      printf("Opzione errata. Riprova.\n");
    }
  }
}
