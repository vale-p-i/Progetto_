#include <stdio.h>
#include <stdlib.h>
#include "box.h"
#include "stack.h"
#include "list.h"
#include "eq.h"

Stack create(int a, int n)
{
  Stack s = newStack();
  int r=a%n;
  while(r){
  push(s, newBox(a/n));
    a=n;
    n=r;
    r=a%n;
  }
  return s;
}

int MCD(int a, int n)
{
  int r=a%n;
  while(r){
    a=n;
    n=r;
    r=a%n;
  }
  return(n);
}

int isCompatible(int a, int n, int b)
{
  if(b%MCD(a,n))
    return 0;
  else
    return 1;
}

int areCompatible(List s, int num)
{
  int i;
  Item item;

  for(i=0;i<num;i++){
      item = searchListPos(s,i);
      if(!isCompatible(get_a(item),get_n(item), get_b(item)))
        return 0;
  }

  return 1;
}

int coprimi(List s, int num)
{
  int i, j, n[num];
  Item item;

  for(i=0;i<num;i++){
      item = searchListPos(s,i);
      n[i]= get_n(item);
  }

  for(i=0;i<num-1;i++)
    for(j=i+1; j<num; j++)
      if(MCD(n[i],n[j]) != 1)
      return 0;

  return 1;
}

void equivalent(int *a, int *b, int *n, int d)
{
  *a/=d;
  *b/=d;
  *n/=d;
}

int Bezout(int a, int n)
{
  Stack s = create(a,n);
  int alpha=0, q=1, b;

  while(!isEmptyStack(s))
  {
    b=q;
    q=q*(-(get_q(top(s))))+alpha;
    alpha=b;
    pop(s);
  }
  return alpha;
}

void equivalent_sistem(List s, int num)
{
  int i, d, sol;
  Item item;

  for(i=0;i<num;i++){
    item = searchListPos(s,i);
    d= MCD(get_a(item),get_n(item));
    equivalent(getA(item),getB(item),getN(item),d);
    sol=((Bezout(get_a(item),get_n(item))) * get_b(item))%get_n(item);

    if(sol<0)
      sol+=get_n(item);
    *getA(item)= 1;
    *getB(item)= sol;
  }
}


List createSistem(int num)
{
  int i;
  List s= newList();

  printf("ax ≡ b (mod n)\n");
  for(i=0; i<num; i++){
    printf("Inserisci equazione %d\n", (i+1));
    addListTail(s, inputItem());
  }

  return s;
}

void eq_cong()
{
  int a,n,b,s;
  printf("Calcolo della risoluzione di un'equazione congruenziale del tipo\n ax ≡ b (mod n)\n");
  printf("Inserisci a:  ");
  scanf("%d", &a);
  printf("Inserisci b:  ");
  scanf("%d", &b);
  printf("Inserisci n:  ");
  scanf("%d", &n);

  if(!isCompatible(a,n,b)){
    printf("L'equazione non ha soluzioni");
    exit(0);
  }

  equivalent(&a,&b,&n,MCD(a,n));
  s=(b*Bezout(a,n))%n;

  if(s<0)
    s+=n;

  printf("Le soluzioni dell'equazione sono i numeri congrui a %d(mod %d)", s, n);

}

void solution(List s, int num)
{
  int n=1, b=0, i;
  Item item;

  for(i=0; i<num; i++) {
    item = searchListPos(s,i);
    *getA(item)= n;
    *getB(item)+= -b;
    b=((Bezout(get_a(item),get_n(item))*get_b(item)*get_a(item))+b)%(get_n(item)*n);
    n=(get_n(item)*n);
    if(b<0)
      b+=n;
  }

  printf("Le soluzioni del sistema sono i numeri congrui a %d(mod %d)", b, n);
}


void sistem()
{
  int num;
  List sistem;

  printf("Quante equazioni presenti nel sistema?\n");
  scanf("%d", &num);

  sistem = createSistem(num);
  if(!areCompatible(sistem,num)){
    printf("Il sistema non ha soluzioni.\n");
    exit(0);
  }

  equivalent_sistem(sistem,num);
  if(!coprimi(sistem,num)){
    printf("Il sistema non ha soluzioni.\n");
    exit(0);
  }

  solution(sistem,num);
}
