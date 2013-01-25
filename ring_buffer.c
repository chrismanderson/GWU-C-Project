#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "ring_buffer.h"


void buffer_init(RingBuffer *rb, int capacity, int item_size)
{
  rb->buffer = malloc(capacity * item_size);
  rb->buffer_end = (char *)rb->buffer + capacity * item_size;
  // if (rb->buffer == NULL) {
  //   // something went wrong. whoops
  // }
  // printf("%d", capacity);
  rb->capacity = capacity;
  rb->count = 0;
  rb->size = item_size;
  rb->head = rb->buffer;
  rb->tail = rb->buffer;
  printf("HELLO\n");
  return;
}

void push(int *file_descriptor, RingBuffer *rb)
{
  printf("COPYING\n");
  memcpy(rb->head, file_descriptor, rb->size);
  printf("memcpy\n");
  rb->head = (char *)rb->head + rb->size;
  if (rb->head == rb->tail) {
    rb->head = rb->buffer;
  }
  rb->count++;
  printf("File Descriptor in push is: %d\n", *file_descriptor);
  return;
}

int test() 
{
  return 3;
}

int popit(RingBuffer *rb)
{
  if (rb->count == 0) {
    return;
  }
  int *popped;
  // int popped = rb->tail;
  printf("Trying to pop\n");
  memcpy(&popped, rb->tail, rb->size);
  printf("Popping value: %d\n", *popped);
  rb->tail = (char *)rb->tail + rb->size;
  

  if (rb->tail == rb->buffer_end) {
    rb->tail = rb->buffer;
  }
  rb->count--;
  printf("returning %d\n", popped);
  return popped;
}

int buffer_size(RingBuffer *rb)
{
  return rb->count;
}