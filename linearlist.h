#ifndef _LINEARLIST_H_
#define _LINEARLIST_H_

#include <stdbool.h>

typedef long long Item;

typedef struct _linearlist_element LinearlistElement;
typedef struct _linearlist Linearlist;

Linearlist *linearlist_create();
void linearlist_destroy(Linearlist **list);
void linearlist_push(Linearlist *list, int pos, Item value);
Item linearlist_pop(Linearlist *list, int pos);
void linearlist_print(Linearlist *list);
LinearlistElement *linearlist_get_first(Linearlist *list);
LinearlistElement *linearlist_get_element_by_position(Linearlist *list, int pos);
Item linearlist_get_value(LinearlistElement *element);
LinearlistElement *linearlist_get_next(LinearlistElement *element);
bool linearlist_is_empty(Linearlist *list);
int linearlist_get_size(Linearlist *list);
//int sz(Linearlist *list);
void linearlist_clear(Linearlist *list);

#endif
