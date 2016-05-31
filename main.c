#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "linearlist.h"

#define LINEARLIST_ERROR	-90000000000000

int linearlist_get_insert_position(Linearlist *list, Item value)
{
	int pos = 0;
	LinearlistElement *el = linearlist_get_first(list);
	while (el != NULL) {
		if (linearlist_get_value(el) >= value)
			break;
		pos++;
		el = linearlist_get_next(el);
	}
	return pos;
}

void linearlist_sort(Linearlist *list)
{
	Linearlist *nw = linearlist_create();
	for (int i = 0; i < linearlist_get_size(list); i++) {
		if (!i) {
			linearlist_push(nw, 0, linearlist_get_value(linearlist_get_element_by_position(list, i)));
			continue;
		}
		Item value = linearlist_get_value(linearlist_get_element_by_position(list, i));
		int pos = linearlist_get_insert_position(list, value);
		linearlist_push(nw, pos, value);
	}
	linearlist_clear(list);
	while (!linearlist_is_empty(nw)) {
		linearlist_push(list, -1, linearlist_pop(nw, 0));
	}
	linearlist_destroy(&nw);
}

int main(void)
{
	Linearlist *linearlist = linearlist_create();
	printf("-------------------------------------------\n");
	printf("Commands:\n");
	printf("a <position> <value> - push to linearlist\n(set position `-1` if you want to pust to the end of linearlist)\n");
	printf("d <position> - pop from linearlist and print popped item\n");
	printf("s - sort linearlist\n");
	printf("p - print linearlist\n");
	printf("l - print linearlist length\n");
	printf("c - clear linearlist\n");
	printf("q - exit\n");
	printf("-------------------------------------------\n");
	while (true) {
		char cmd;
		Item value = 0;
		int pos = 0;
		bool is_finished = false;
		scanf("%c", &cmd);
		long long tmp;
		switch (cmd) {
			case 'q':
				is_finished = true;
				break;
			case 'a':
				scanf("%d", &pos);
				scanf("%lld", &value);
				linearlist_push(linearlist, pos, value);
				break;
			case 'd':
				scanf("%d", &pos);
				tmp = (long long) linearlist_pop(linearlist, pos);
				if (tmp != LINEARLIST_ERROR) printf("%lld\n", tmp);
				break;
			case 's':
				linearlist_sort(linearlist);
				break;
			case 'p':
				linearlist_print(linearlist);
				break;
			case 'l':
				printf("%d\n", linearlist_get_size(linearlist));
				//printf("%d\n", sz(linearlist));
				break;
			case 'c':
				//printf("%d\n", linearlist_get_size(linearlist));
				linearlist_clear(linearlist);
				break;
			case '\n':
				break;
			default:
				printf("Invalid command `%c`\n", cmd);
				break;
		}
		if (is_finished) break;
	}
	printf("Goodbye!\n");

	return 0;
}
