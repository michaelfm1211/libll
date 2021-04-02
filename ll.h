#pragma once

#include <stdbool.h>

typedef struct ll_node {
  void *data;
  struct ll_node *prev;
  struct ll_node *next;
} ll_node_t;

typedef struct ll_linked_list {
  ll_node_t *head;
  ll_node_t *tail;
} ll_t;

// create new linked list
ll_t *ll_new();
// free linked list
void ll_free(ll_t *ll);

// created new node by passing malloc'd pointer
ll_node_t *ll_node_new(void *data);
void ll_node_free(ll_node_t *node);

// append a node to the list
void ll_append_raw(ll_t *ll, ll_node_t *node);
// append a malloc'd pointer onto the list
void ll_append(ll_t *ll, void *data);
// append a non-malloc'd int onto the list
void ll_append_int(ll_t *ll, int data);

// if prepend is false, insert node after index, if true insert before index
// will return 0 on success and 1 if index is out of bounds
int ll_insert_raw(ll_t *ll, ll_node_t *node, int index, bool prepend);
// wrapper for ll_insert_raw; will create node with data before calling
// ll_insert_raw
int ll_insert(ll_t *ll, void *data, int index, bool prepend);
// wrapper for ll_insert; will malloc data before calling ll_insert
int ll_insert_int(ll_t *ll, int data, int index, bool prepend);

// get node from index; returns null if index nonexistant
ll_node_t *ll_get_raw(ll_t *ll, int index);

// get data from index; returns null if index nonexistant
void *ll_get(ll_t *ll, int index);

// delete data from index; do nothing if index nonexistant
void ll_del(ll_t *ll, int index);

// return length of linked list
int ll_len(ll_t *ll);

// shorthand for looping over every element in a linked list
#define LL_ITER(ll) for (int i = 0; i < ll_len(ll); i++)

// print the addresses of the nodes
void ll_print_nodes(ll_t *ll);

// print the addresses of the data
void ll_print_addr(ll_t *ll);
// print the data as integers
void ll_print_int(ll_t *ll);
