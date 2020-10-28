#pragma once

typedef struct node {
  void *data;
  struct node *prev;
  struct node *next;
} node_t;

typedef struct linked_list {
  node_t *head;
  node_t *tail;
} ll_t;

// create new linked list
ll_t *ll_new();
// free linked list
void ll_free(ll_t *ll);

// created new node by passing malloc'd pointer
node_t *ll_node_new(void *data);
void ll_node_free(node_t *node);

// append a node to the list
void ll_append_raw(ll_t *ll, node_t *node);
// append a malloc'd pointer onto the list
void ll_append(ll_t *ll, void *data);
// append a non-malloc'd int onto the list
void ll_append_int(ll_t *ll, int data);

// get data from index; returns null if index nonexistant
void *ll_get(ll_t *ll, int index);

// delete data from index; do nothing if index nonexistant
void ll_del(ll_t *ll, int index);

// return length of linked list
int ll_len(ll_t *ll);

// shorthand for looping over every element in a linked list
#define LL_ITER(ll) for (int i = 0; i < ll_len(ll); i++)

// print the addresses of the data
void ll_print_addr(ll_t *ll);
// print the data as integers
void ll_print_int(ll_t *ll);
