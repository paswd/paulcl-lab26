#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "linearlist.h"

/*struct _linearlist_leave {
	Item value;
	Linearlist_leave *branches[2];
};*/

struct _linearlist {
	Item value;
	Linearlist *next;
};

Linearlist *linearlist_create(Linearlist *first, Linearlist *nxt, Item value)
{
	Linearlist *nw = (Linearlist *) calloc(1, sizeof(Linearlist));
	nw->value = value;
	if (first == NULL) {
		nw->next = NULL;
		return nw;
	}
	if (first == nxt) {
		nw->next = first;
		return nw;
	}

	Linearlist *tmp = first;
	while (tmp->next != nxt && tmp->next != NULL) {
		tmp = tmp->next;
	}
	nw->next = tmp->next;
	tmp->next = nw;
	return first;
}
void linearlist_destroy(Linearlist **first)
{
	Linearlist *ths = *first;
	while (ths != NULL) {
		Linearlist *tmp = ths->next;
		free(ths);
		ths = tmp;
	}
	*first = NULL;
}

void linearlist_print(Linearlist *list)
{
	while (list != NULL) {
		printf("%lld ", list->value);
		list = list->next;
	}
	printf("\n");
}

Item linearlist_getvalue(Linearlist *element)
{
	return element->value;
}
Linearlist *linearlist_getnext(Linearlist *element)
{
	return element->next;
}