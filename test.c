#include <stdio.h>

#include <stdbool.h>
#include "ll.h"
#include "minunit.h"

MU_TEST(test_ll_new) {
  ll_t *ll = ll_new();
  mu_check(ll->head == NULL);
  mu_check(ll->tail == NULL);
  ll_free(ll);
}

MU_TEST(test_ll_append) {
  ll_t *ll = ll_new();
  ll_append_int(ll, 1);
  ll_append_int(ll, 2);

  int head_data = *(int *)(ll->head->data);
  mu_assert_int_eq(1, head_data);

  int tail_data = *(int *)(ll->tail->data);
  mu_assert_int_eq(2, tail_data);
}

MU_TEST(test_ll_insert) {
  ll_t *ll = ll_new();
  ll_append_int(ll, 1);
  ll_append_int(ll, 2);
  // at this point list should be [1, 2]

  int result;
  result = ll_insert_int(ll, 3, 0, false);
  mu_assert_int_eq(0, result);
  // at this point list should be [1, 3, 2]
  result = ll_insert_int(ll, 4, 0, true);
  mu_assert_int_eq(0, result);
  // at this point list should be [4, 1, 3, 2]
  result = ll_insert_int(ll, 5, -1, false);
  mu_assert_int_eq(0, result);
  // at this point list should be [4, 1, 3, 2, 5]

  int head_data = *(int *)(ll->head->data);
  mu_assert_int_eq(4, head_data);

  int tail_data = *(int *)(ll->tail->data);
  mu_assert_int_eq(5, tail_data);

  ll_free(ll);
}

MU_TEST(test_ll_get) {
  ll_t *ll = ll_new();

  ll_append_int(ll, 0);
  ll_append_int(ll, 1);
  ll_append_int(ll, 2);

  int *data = ll_get(ll, 1);
  if (data == NULL) {
    mu_fail("ll_get returned NULL on positive index");
  }
  mu_assert_int_eq(1, *data);

  data = ll_get(ll, -1);
  if (data == NULL) {
    mu_fail("ll_get returned NULL on negative index");
  }
  mu_assert_int_eq(2, *data);

  ll_free(ll);
}

MU_TEST(test_ll_del) {
  ll_t *ll = ll_new();

  ll_append_int(ll, 0);
  ll_append_int(ll, 1);
  ll_append_int(ll, 2);

  ll_del(ll, 1);

  int *data = ll_get(ll, 1);
  mu_assert_int_eq(2, *data);

  ll_free(ll);
}

MU_TEST(test_ll_len) {
  ll_t *ll = ll_new();

  ll_append_int(ll, 0);
  ll_append_int(ll, 1);
  ll_append_int(ll, 2);

  mu_assert_int_eq(3, ll_len(ll));

  ll_free(ll);
}

MU_TEST(test_ll_iter) {
  ll_t *ll = ll_new();

  ll_append_int(ll, 0);
  ll_append_int(ll, 1);
  ll_append_int(ll, 2);

  mu_assert_int_eq(ll_len(ll), 3);

  ll_free(ll);
}

MU_TEST_SUITE(test_ll) {
  MU_RUN_TEST(test_ll_new);
  MU_RUN_TEST(test_ll_append);
  MU_RUN_TEST(test_ll_insert);
  MU_RUN_TEST(test_ll_get);
  MU_RUN_TEST(test_ll_del);
  MU_RUN_TEST(test_ll_len);
  MU_RUN_TEST(test_ll_iter);
}

int main() {
  MU_RUN_SUITE(test_ll);
  MU_REPORT();
  return MU_EXIT_CODE;
}