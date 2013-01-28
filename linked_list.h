#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct request_list {
  struct request_node *head;
} request_list;

typedef struct request_node {
  int file_descriptor;
  struct request_node *next;
} request_node;

void request_list_init();
request_node* init_node(int fd);
void push_fd(request_node *list, int data);
request_node* get_request();
request_node* pop_request(request_node *list);
void put_request(request_node *r);

extern request_node *requests;
#endif
