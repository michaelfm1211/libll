#include <stdio.h>

#include "ll.h"
#include "minunit.h"

MU_TEST(test_ll_new) {
  ll_t *ll = ll_new();
  mu_check(ll->head == NULL);
  mu_check(ll->tail == NULL);
  ll_free(ll);
}

MU_TEST(test_ll_get) {
  ll_t *ll = ll_new();

  ll_append_int(ll, 0);
  ll_append_int(ll, 1);
  ll_append_int(ll, 2);

  int *data = ll_get(ll, 1);
  if (data == NULL) {
    mu_fail("ll_get returned NULL");
  }
  mu_check(*data == 1);

  ll_free(ll);
}

MU_TEST_SUITE(test_ll) {
  MU_RUN_TEST(test_ll_new);
  MU_RUN_TEST(test_ll_get);
}

int main() {
  MU_RUN_SUITE(test_ll);
  MU_REPORT();
  return MU_EXIT_CODE;
}