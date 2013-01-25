#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "ring_buffer.h"


void buffer_init(RingBuffer *rb, size_t capacity, size_t item_size)
{
  rb->buffer = malloc(capacity * item_size);
  // if (rb->buffer == NULL) {
  //   // something went wrong. whoops
  // }
  rb->buffer_end = (char *)rb->buffer + capacity * item_size;
  rb->capacity = capacity;
  rb->count = 0;
  rb->item_size = item_size;
  rb->head = rb->buffer;
  rb->tail = rb->buffer;
  return;
}

void push(int *file_descriptor, RingBuffer *rb)
{
  memcpy(rb->head, file_descriptor, rb->item_size);
  rb->head = (char *)rb->head + rb->item_size;
  if (rb->head == rb->buffer_end) {
    rb->head = rb->buffer;
  }
  rb->count++;
  printf("Buffer size is %d", rb->count);
  return;
}

int test() 
{
  return 3;
}

void popit(RingBuffer *rb, void *item)
{
  if (rb->count == 0) {
    return;
  }
  // int popped = rb->tail;
  // printf("Trying to pop\n");
  memcpy(item, rb->tail, rb->item_size);
  // printf("Popping value: %d\n", item);
  rb->tail = (char *)rb->tail + rb->item_size;
  
  if (rb->tail == rb->buffer_end) {
    rb->tail = rb->buffer;
  }
  rb->count--;
  // printf("returning %d\n", (int *)item);
}

int buffer_size(RingBuffer *rb)
{
  return rb->count;
}