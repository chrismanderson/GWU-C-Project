#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if !defined(__APPLE__)
  #include <malloc.h>
#endif
#include "linked_list.h"

void request_node_init(request_node *list)
{
  list->next = NULL;
}
void request_node_add(request_node *list, int *data)
{
  request_node *new_node = (request_node *)malloc(sizeof(request_node));
  list->next = new_node;
  new_node->file_descriptor = &data;

  printf("Node data is %d", data);
}

void put_request_node(request_node *list, int *data)
{

}