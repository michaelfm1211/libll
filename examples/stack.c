#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../ll.h"

void push(ll_t *stack, const char *str) {
	char *malloc_str = malloc(16);
	strncpy(malloc_str, str, 16);
	ll_append(stack, malloc_str);
}

char *pop(ll_t *stack) {
	char *str = ll_get(stack, -1);
	printf("[LO] %d\n", ll_len(stack));
	ll_print_nodes(stack);
	ll_del(stack, -1);
	return str;
}

int main() {
	ll_t *stack = ll_new();
	printf("STACK: %p\n", stack);
	while (ll_len(stack) < 5) {
		char str[16];
		printf("(up to 16 chars): ");
		fgets(str, 16, stdin);
		push(stack, str);
		// ll_print_nodes(stack);
	}

	for(int i = 0; i < 5; i++) {
		printf("%s", pop(stack));
	}

	printf("%d\n", ll_len(stack));
	ll_print_nodes(stack);

	ll_free(stack);
}