#include <stdio.h>
#include "item.h"
#include "eq.h"

Item inputItem()
{
  int a, b, n;
  printf("Inserisci a: ");
  scanf("%d", &a);
  printf("Inserisci b: ");
  scanf("%d", &b);
  printf("Inserisci n: ");
  scanf("%d", &n);

  return newEq(a,b,n);
}
