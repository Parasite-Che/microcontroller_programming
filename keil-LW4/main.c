#include <stdlib.h>
#include "list.h"
#include <inttypes.h>

int main(){
	node *list = initialize_head(10);
	add_node(list, 123);
	add_node(list, 62);
	add_node(list, 661);
	add_node(list, 15);
	add_node(list, 112);
	add_node(list, 272);
	add_node(list, 510);
	while(list->next != NULL){
		if (list->next->value == 112){
			delete_node(list->next);
			delete_root(list);
		}
		list = list->next;
	}
	list = list->head;
	sorting(list);
	list = list->head;
	while(list->next != NULL){
		list = list->next;
	}
	return 0;
}
