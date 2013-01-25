#ifndef RING_BUFFER_H
#define RING_BUFFER_H

typedef struct RingBuffer{
  int count;
  int *head;
  int *tail;
  int *buffer;
  int *buffer_end;
  int capacity;
  int size;
} RingBuffer;

void buffer_init(RingBuffer *rb, int capacity, int item_size);
void push(int *file_descriptor, RingBuffer *rb);
int test();
int popit(RingBuffer *rb);
int buffer_size(RingBuffer *rb);

#endif