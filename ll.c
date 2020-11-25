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
    node_t *next_node = node->next;
    ll_node_free(node);
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

void ll_node_free(node_t *node) {
  free(node->data);
  free(node);
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

  // b/c its python style, 0 is first, but -1(not -0) is last, so we must
  // add one. ex: -1 becomes 0 from the end
  if (!pos) index++;

  int i = 0;
  while (node != NULL) {
    if (i == index) {
      return node->data;
    }
    node = pos ? node->next : node->prev;
    pos ? i++ : i--;
  }

  return NULL;
}

void ll_del(ll_t *ll, int index) {
  if (index == 0) {
    node_t *oldhead = ll->head;
    ll->head = ll->head->next;
    if(ll->head != NULL) ll->head->prev = NULL;
    if(ll->head == NULL) ll->tail = NULL;
    ll_node_free(oldhead);
    return;
  } else if (index == -1) {
    node_t *oldtail = ll->tail;
    ll->tail = ll->tail->prev;
    if(ll->tail != NULL) ll->tail->next = NULL;
    if(ll->tail == NULL) ll->head = NULL;
    ll_node_free(oldtail);
    return;
  }

  bool pos = index > 0 ? true : false;
  node_t *node = pos ? ll->head : ll->tail;

  // b/c its python style, 0 is first, but -1(not -0) is last, so we must
  // add one. ex: -1 becomes 0 from the end
  if (!pos) index++;

  int i = 0;
  while (node != NULL) {
    if (i == index) {
      if(node->prev != NULL)  node->prev->next = node->next;
      if(node->next != NULL)  node->next->prev = node->prev;
      ll_node_free(node);
    }
    node = pos ? node->next : node->prev;
    pos ? i++ : i--;
  }
}

int ll_len(ll_t *ll) {
  node_t *node = ll->head;
  int len = 0;
  while (node != NULL) {
    len++;
    node = node->next;
  }

  return len;
}

void ll_print_nodes(ll_t *ll) {
  node_t *node = ll->head;
  while (node != NULL) {
    printf("%p-", node);
    node = node->next;
  }
  printf("\n");
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
