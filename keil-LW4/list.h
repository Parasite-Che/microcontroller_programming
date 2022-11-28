#ifndef __LIST__
#define __LIST__

typedef struct node {
  int value;
	struct node *head;
  struct node *next;
} node;

node *initialize_head(int value);
void add_node(node *back, int value);
void delete_node(node *n);
void delete_root(node *n);
void sorting(node *n);

#endif
