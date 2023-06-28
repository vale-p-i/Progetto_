#include "item.h"

typedef struct list *List;

List newList();
int isEmpty(List);
void addHead(List, Item);
Item removeHead(List);
Item getHead(List);
int sizeList(List);
Item removeListItem(List, Item);
Item removeListPos(List, int);
Item searchListPos(List, int);
int addListPos(List, Item, int);
int addListTail(List, Item);
void reverseList(List);
List cloneList(List);
