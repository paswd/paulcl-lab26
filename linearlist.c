#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "linearlist.h"

#define LINEARLIST_ERROR	-90000000000000

struct _linearlist_element {
	Item value;
	LinearlistElement *next;
};

struct _linearlist {
	LinearlistElement *first;
	int size;
};

Linearlist *linearlist_create()
{
	Linearlist *nw = (Linearlist *) calloc(1, sizeof(Linearlist));
	nw->size = 0;
	nw->first = NULL;
	return nw;
}

void linearlist_destroy(Linearlist **list)
{
	LinearlistElement *del = (*list)->first;
	while (del != NULL) {
		LinearlistElement *tmp = del->next;
		free(del);
		del = tmp;
	}
	free (*list);
	*list = NULL;
}

void linearlist_push(Linearlist *list, int pos, Item value)
{
	if (pos > list->size || pos < 0)
		pos = list->size;
	list->size++;
	LinearlistElement *nw = (LinearlistElement *) calloc(1, sizeof(LinearlistElement));
	nw->next = NULL;
	nw->value = value;
	int i = 0;
	if (pos == 0) {
		nw->next = list->first;
		list->first = nw;
		return;
	}
	LinearlistElement *tmp = list->first;
	while (i < pos - 1 && tmp->next != NULL) {
		i++;
		tmp = tmp->next;
	}
	nw->next = tmp->next;
	tmp->next = nw;
}

Item linearlist_pop(Linearlist *list, int pos)
{
	if (list->size == 0) {
		printf("Linearlist is empty\n");
		return LINEARLIST_ERROR;
	}
	list->size--;
	Item value;
	LinearlistElement *tmp = list->first;
	if (pos == 0) {
		value = tmp->value;
		list->first = tmp->next;
		free(tmp);
		return value;
	}
	int i = 0;
	while (i < pos - 1) {
		if (tmp->next == NULL) {
			printf("Element is out of range\n");
			return LINEARLIST_ERROR;
		}

		i++;
		tmp = tmp->next;
	}
	LinearlistElement *del = tmp->next;
	tmp->next = del->next;
	value = del->value;
	free(del);
	return value;
}

void linearlist_print(Linearlist *list)
{
	LinearlistElement *tmp = list->first;
	while (tmp != NULL) {
		printf("%lld ", tmp->value);
		tmp = tmp->next;
	}
	printf("\n");
}

LinearlistElement *linearlist_get_first(Linearlist *list)
{
	return list->first;
}
LinearlistElement *linearlist_get_element_by_position(Linearlist *list, int pos)
{
	if (pos >= list->size || pos < 0) {
		printf("Element is out of range\n");
		return NULL;
	}
	LinearlistElement *tmp = list->first;
	for (int i = 0; i < pos && tmp != NULL; i++) {
		tmp = tmp->next;
	}
	return tmp;
}

Item linearlist_get_value(LinearlistElement *element)
{
	return element->value;
}
LinearlistElement *linearlist_get_next(LinearlistElement *element)
{
	return element->next;
}

bool linearlist_is_empty(Linearlist *list)
{
	if (list->first != NULL)
		return false;
	return true;
}

int linearlist_get_size(Linearlist *list)
{
	return list->size;
}
/*int sz(Linearlist *list)
{
	LinearlistElement *tmp = list->first;
	int cnt = 0;
	while (tmp != NULL) {
		cnt++;
		tmp = tmp->next;
	}
	return cnt;
}*/

void linearlist_clear(Linearlist *list)
{
	LinearlistElement *del = list->first;
	while (del != NULL) {
		LinearlistElement *tmp = del->next;
		free(del);
		del = tmp;
	}
	list->first = NULL;
	list->size = 0;
}
