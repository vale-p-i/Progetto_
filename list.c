#include"list.h"
#include<stdlib.h>

struct list
{
    int size;
    struct node *head;

};

struct node
{
    Item value;
    struct node *next;
};

List newList()
{
    List l=malloc(sizeof(struct list));
    l->size=0;
    l->head=NULL;
    return l;
}


int isEmpty(List l)
{
    if(l->size==0)
        return 1;
    return 0;
}


void addHead(List l, Item elem)
{
    struct node *n= malloc(sizeof(struct node));
    n->value=elem;
    n->next=l->head;
    l->head=n;
    (l->size)++;
}


Item removeHead(List l)
{
    Item elem;
    struct node *t;
    if(isEmpty(l))
        return NULL;
    t=l->head;
    l->head=t->next;
    elem=t->value;
    free(t);
    (l->size)--;
    return elem;
}


Item getHead(List l)
{
    if(isEmpty(l))
        return NULL;
    return l->head->value;
}


int sizeList(List l)
{
    return l->size;
}





Item removeListPos(List l, int pos)
{
	if(isEmpty(l))
		return NULL;

	struct node *prev;
	struct node *p;
	Item val;
	int i=0;

	for(p=l->head; p!=NULL; prev=p, p=p->next, i++)
        if(i==pos){
        	if(p == l->head)
        		return removeHead(l);
        	else{
        		prev->next = p->next;
        		val = p->value;
        		free(p);
        		(l->size)--;
        		return val;
        	}
        }
    return NULL;

}

int addListPos(List l, Item e, int pos)
{
    if(pos >= 0 && pos<= l->size)
    {
        struct node *p;
        struct node *new = malloc(sizeof(struct node));
        int i;

        if(pos == 0)
        {
            addHead(l, e);
            return 1;
        }

        for(p = l->head, i = 0; i < pos-1 ; p = p->next, i++);

        new->next = p->next;
        p->next = new;
        new->value = e;
        (l->size)++;

        return 1;
    }
    else return 0;
}



Item searchListPos(List l, int pos)
{
  int i = 0;
  struct node *p;

  for(p = l->head; p != NULL; p = p->next, i++)
    if(i == pos)
      return p->value;

  return NULL;
}

int addListTail(List l, Item e)
{
    return addListPos(l, e, l->size);
}

void reverseList(List l)
{
    struct node *prev, *p, *temp;

    for(prev = NULL, p = l->head ; p != NULL ; prev = p, p = temp)
    {
        temp = p->next;
        p->next = prev;
    }
    l->head = prev;
}

List cloneList(List l)
{
    List l1 = newList();
    struct node *p;

    for(p = l->head ; p != NULL ; p = p->next)
        addListTail(l1, p->value);


    return l1;
}
