#include "list.h"
#include <string.h>
#include <stdlib.h>

node *initialize_head(int value){
	node *head = (node*)malloc(sizeof(node));
	head->head = head;
	head->value = value;
	head->next = NULL;
	return head;
}

void add_node(node *back, int value){
	node *tmp = (node*)malloc(sizeof(node));
	if (tmp != NULL){
		tmp->head = back->head;
		tmp->value = value;
		tmp->next = back->next;
		back->next = tmp;
	}
}

void delete_node(node *n){
	node *pointer = NULL;
	pointer = n->head;
	
	while(pointer->next != n){
		pointer = pointer->next;
	}
	pointer->next = n->next;
	n->value = NULL;
	n->head = NULL;
	n->next = NULL;
	free(n);
}

void delete_root(node *n){
	node *head = n->head;
	node *pointer = head->next;
	head->next->head = head->next;
	head->next = NULL;
	head->head = NULL;
	head->value = NULL;
	free(head);
	while (pointer->next != NULL){
		pointer->next->head = pointer->head;
		pointer = pointer->next;
	}
}

void sorting(node *n){
	node *pointer = n->head;
	char tf = 'f';
	while (tf == 'f'){
		tf = 't';
		while (pointer->next != NULL){
			if(pointer->value > pointer->next->value){
				pointer->value ^= pointer->next->value; 
				pointer->next->value ^= pointer->value;
				pointer->value ^= pointer->next->value;
				tf = 'f';
			}
			else{
				pointer = pointer->next;
			}
		}
		pointer = pointer->head;
	}
}
