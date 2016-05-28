#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "linearlist.h"

Linearlist *get_position_to_value(Linearlist *first, Item value)
{
	Linearlist *tmp = first;
	while (tmp != NULL) {
		if (linearlist_getvalue(tmp) >= value)
			break;
		tmp = linearlist_getnext(tmp);
	}
	return tmp;
}

int main(void)
{
	int n;
	scanf("%d", &n);

	Linearlist *list = NULL;

	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		list = linearlist_create(list, get_position_to_value(list, tmp), tmp);
	}
	//printf("Point 1\n");
	linearlist_print(list);
	linearlist_destroy(&list);
	return 0;
}