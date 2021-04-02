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
  ll_node_t *node = ll->head;
  while (node != NULL) {
    ll_node_t *next_node = node->next;
    ll_node_free(node);
    node = next_node;
  }

  free(ll);
}

ll_node_t *ll_node_new(void *data) {
  ll_node_t *node = malloc(sizeof(ll_node_t));
  node->data = data;
  node->prev = NULL;
  node->next = NULL;
  return node;
}

void ll_node_free(ll_node_t *node) {
  free(node->data);
  free(node);
}

void ll_append_raw(ll_t *ll, ll_node_t *node) {
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
  ll_node_t *node = ll_node_new(data);
  ll_append_raw(ll, node);
}

void ll_append_int(ll_t *ll, int data) {
  int *malloc_pointer = malloc(sizeof(data));
  *malloc_pointer = data;
  ll_append(ll, malloc_pointer);
}

int ll_insert_raw(ll_t *ll, ll_node_t *node, int index, bool prepend) {
  if (index >= ll_len(ll)) return 1;

  // before we can insert node, we need to know which nodes
  // the inserted node will be between
  ll_node_t *node_prev, *node_next;

  if(!prepend) {
    node_prev = ll_get_raw(ll, index);
    if(node_prev == NULL) return 1;
    node_next = node_prev->next;
  } else {
    node_next = ll_get_raw(ll, index);
    if(node_next == NULL) return 1;
    node_prev = node_next->prev;
  }

  // now, change prev and next nodes to now include new node
  if(node_prev != NULL) node_prev->next = node;
  node->prev = node_prev;

  if(node_next != NULL) node_next->prev = node;
  node->next = node_next;

  // if node_prev was ll->tail or node_next was ll->head, adjust them
  if(ll->tail == node_prev) ll->tail = node;
  if(ll->head == node_next) ll->head = node;

  return 0;
}

int ll_insert(ll_t *ll, void *data, int index, bool prepend) {
  ll_node_t *node = ll_node_new(data);
  int retval = ll_insert_raw(ll, node, index, prepend);
  return retval;
}

int ll_insert_int(ll_t *ll, int data, int index, bool prepend) {
  int *malloc_pointer = malloc(sizeof(data));
  *malloc_pointer = data;
  int retval = ll_insert(ll, malloc_pointer, index, prepend);
  return retval;
}

ll_node_t *ll_get_raw(ll_t *ll, int index) {
  if (index >= ll_len(ll)) return NULL;
  if (index == 0) return ll->head;

  bool pos = index > 0 ? true : false;
  ll_node_t *node = pos ? ll->head : ll->tail;

  // b/c its python style, 0 is first, but -1(not -0) is last, so we must
  // add one. ex: -1 becomes 0 from the end
  if (!pos) index++;

  int i = 0;
  while (node != NULL) {
    if (i == index) {
      return node;
    }
    node = pos ? node->next : node->prev;
    pos ? i++ : i--;
  }

  return NULL;
}

void *ll_get(ll_t *ll, int index) {
  ll_node_t *node = ll_get_raw(ll, index);
  return node->data;
}

void ll_del(ll_t *ll, int index) {
  if (index == 0) {
    ll_node_t *oldhead = ll->head;
    ll->head = ll->head->next;
    if (ll->head != NULL) ll->head->prev = NULL;
    if (ll->head == NULL) ll->tail = NULL;
    ll_node_free(oldhead);
    return;
  } else if (index == -1) {
    ll_node_t *oldtail = ll->tail;
    ll->tail = ll->tail->prev;
    if (ll->tail != NULL) ll->tail->next = NULL;
    if (ll->tail == NULL) ll->head = NULL;
    ll_node_free(oldtail);
    return;
  }

  bool pos = index > 0 ? true : false;
  ll_node_t *node = pos ? ll->head : ll->tail;

  // b/c its python style, 0 is first, but -1(not -0) is last, so we must
  // add one. ex: -1 becomes 0 from the end
  if (!pos) index++;

  int i = 0;
  while (node != NULL) {
    if (i == index) {
      if (node->prev != NULL) node->prev->next = node->next;
      if (node->next != NULL) node->next->prev = node->prev;
      ll_node_free(node);
    }
    node = pos ? node->next : node->prev;
    pos ? i++ : i--;
  }
}

int ll_len(ll_t *ll) {
  ll_node_t *node = ll->head;
  int len = 0;
  while (node != NULL) {
    len++;
    node = node->next;
  }

  return len;
}

void ll_print_nodes(ll_t *ll) {
  ll_node_t *node = ll->head;
  while (node != NULL) {
    printf("%p-", node);
    node = node->next;
  }
  printf("\n");
}

void ll_print_addr(ll_t *ll) {
  ll_node_t *node = ll->head;
  while (node != NULL) {
    printf("%p-", node->data);
    node = node->next;
  }
  printf("\n");
}

void ll_print_int(ll_t *ll) {
  ll_node_t *node = ll->head;
  while (node != NULL) {
    printf("%d-", *(int *)node->data);
    node = node->next;
  }
  printf("\n");
}
