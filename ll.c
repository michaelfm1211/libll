#include "ll.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

ll_t *ll_new() {
  ll_t *ll = malloc(sizeof(ll_t));
  ll->head = NULL;
  ll->tail = NULL;
  return ll;
}

void ll_free(ll_t *ll) {
  node_t *node = ll->head;
  while (node != NULL) {
    free(node->data);
    node_t *next_node = node->next;
    free(node);
    node = next_node;
  }

  free(ll);
}

node_t *ll_node_new(void *data) {
  node_t *node = malloc(sizeof(node_t));
  node->data = data;
  node->prev = NULL;
  node->next = NULL;
  return node;
}

void ll_append_raw(ll_t *ll, node_t *node) {
  node->prev = ll->tail;
  node->next = NULL;

  if (ll->tail == NULL) {
    ll->head = node;
  } else {
    ll->tail->next = node;
  }
  ll->tail = node;
}

void ll_append(ll_t *ll, void *data) {
  node_t *node = ll_node_new(data);
  ll_append_raw(ll, node);
}

void ll_append_int(ll_t *ll, int data) {
  int *malloc_pointer = malloc(sizeof(data));
  *malloc_pointer = data;
  ll_append(ll, malloc_pointer);
}

void *ll_get(ll_t *ll, int index) {
  if (index == 0) return ll->head->data;

  bool pos = index > 0 ? true : false;
  node_t *node = pos ? ll->head : ll->tail;

  int i = 0;
  while (node != NULL) {
    if (i == index) {
      return node->data;
    }
    node = pos ? node->next : node->prev;
    i++;
  }

  return NULL;
}

void ll_print_addr(ll_t *ll) {
  node_t *node = ll->head;
  while (node != NULL) {
    printf("%p-", node->data);
    node = node->next;
  }
  printf("\n");
}

void ll_print_int(ll_t *ll) {
  node_t *node = ll->head;
  while (node != NULL) {
    printf("%d-", *(int *)node->data);
    node = node->next;
  }
  printf("\n");
}
