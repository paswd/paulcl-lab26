#ifndef _LINEARLIST_H_
#define _LINEARLIST_H_

#include <stdbool.h>

typedef long long Item;

typedef struct _linearlist Linearlist;

Linearlist *linearlist_create(Linearlist *first, Linearlist *nxt, Item value);
void linearlist_destroy(Linearlist **first);
void linearlist_print(Linearlist *list);
Item linearlist_getvalue(Linearlist *element);
Linearlist *linearlist_getnext(Linearlist *element);

#endif
