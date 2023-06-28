#include <stdlib.h>
#include "box.h"

struct box {
  int q;
};

Box newBox(int q)
{
  Box b = malloc(sizeof(struct box));
  b->q = q;

  return b;
}

int get_q(Box b)
{
  return b->q;
}
