#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct request_node {
  int file_descriptor;
  struct request_node *next;
} request_node;

void request_node_init(request_node *list);
void put_request_node(request_node *list, int *data);
void get_requeset(request_node *r);

#endif