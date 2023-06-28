#include <stdlib.h>
#include "eq.h"

struct equation {
  int a;
  int b;
  int n;
};

Equation newEq(int a, int b, int n)
{
  Equation e = malloc(sizeof(struct equation));
  e->a=a;
  e->b=b;
  e->n=n;

  return e;
}

int get_a(Equation e)
{
  return e->a;
}

int get_b(Equation e)
{
  return e->b;
}

int get_n(Equation e)
{
  return e->n;
}

int *getA(Equation e)
{
  return &(e->a);
}

int *getB(Equation e)
{
  return &(e->b);
}

int *getN(Equation e)
{
  return &(e->n);
}
