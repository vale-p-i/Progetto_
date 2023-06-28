#include <stdlib.h>
#include "stack.h"
#include "list.h"

struct stack{
  List elements;
};

Stack newStack(){
  Stack s = malloc(sizeof(struct stack));
  s->elements = newList();

  return s;
}

int isEmptyStack(Stack s){
  return isEmpty(s->elements);
}

int push(Stack s, Item el){
  addHead(s->elements, el);
  return 1;
}

int pop(Stack s){
  if(removeHead(s->elements) == NULL)
    return 0;

  return 1;
}

Item top(Stack s){
  return getHead(s->elements);
}
