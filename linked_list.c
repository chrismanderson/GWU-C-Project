#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if !defined(__APPLE__)
  #include <malloc.h>
#endif
#include "linked_list.h"

request_node *top = NULL;

request_node *requests;

request_node* get_request()
{
  while (requests->file_descriptor == NULL) {
    // no nothing
  }

    request_node *temp;
    temp = requests->next;
    requests = temp;

    printf("temp fd %d", temp->file_descriptor);

    return requests;
  // int rta = list->file_descriptor;
  // printf("rta is %d\n", list->file_descriptor);
  // *data = rta;
  // list = list->next;

}

request_node* init_node(int fd)
{
  request_node *new_node = (request_node *)malloc(sizeof(request_node));
  new_node->file_descriptor = fd;
  return new_node;

}


void request_list_init()
{
  requests = (request_node *)malloc(sizeof(request_node));

  requests->next = NULL;
  requests->file_descriptor = NULL;

}

void put_request(request_node *r)
{
  if (requests->file_descriptor == NULL) {
    requests = r;
  } else {
    printf("orig requests fd %d\n", requests->file_descriptor);

    r->next = requests;
    requests = r;

    printf("new requests fd %d\n", requests->file_descriptor);

  }
  // request_nod
}
// void push_fd(request_node *node, int data)
// {
//   request_node *new_node;
//   new_node = (request_node *)malloc(sizeof(request_node));
//   new_node->file_descriptor = data;

//   if (list->head == NULL) {
//     list
//   }
  
//   new_node->next = list;

//   printf("new_node fd %d", new_node->file_descriptor);
//   printf("new_node next %d", new_node->next);


//   return;
// }


  // printf("\n\nNew Loop\n"); 
  // printf("Current request_node is %d\n", list->file_descriptor);
  // request_node *new_node;
  // if (list->file_descriptor == NULL) {
  //   printf("null?\n");
  //   list->file_descriptor = *data;
  //   printf("fd is %d\n", list->file_descriptor);

  // } else {
  //   new_node = (request_node *)malloc(sizeof(request_node));
  //   new_node->next = NULL;
  //   printf("next node is %d\n", list->next);
  //   new_node->file_descriptor = *data;
  //   new_node->next = list;
  //   &list = new_node;
  //   printf("List after alteration is %d\n", list->file_descriptor);
  // }

  // count++;

  // // while (list->next != NULL) {
  // //   printf("Current loop is %d\n", list->file_descriptor);
  // //   list = list->next;
  // // }

  // // printf("fd data is %d\n", new_node->file_descriptor);

  // // printf("node is %d\n", new_node);

  // printf("Count is %d", count);
// }

// request_node* pop_request(request_node *list)
// {
//   printf("lost fd %d", list->file_descriptor);

//   request_node *temp;
//   temp = list->next;

//   printf("temp fd %d", temp->file_descriptor);

//   return temp;
//   // int rta = list->file_descriptor;
//   // printf("rta is %d\n", list->file_descriptor);
//   // *data = rta;
//   // list = list->next;
//   // printf("node is is %d\n", &list->next);
  
  
// }
