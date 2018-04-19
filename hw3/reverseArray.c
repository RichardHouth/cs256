/*
 * reverseArray.c
 *
 *  Created on: Apr 18, 2018
 *      Author: richardhouth
 */

#include <stdio.h>

void input_integer(int **a, size_t *n);
void inverse(int *a, size_t n);
int main() {
	int *a;
	size_t n;

	input_integer(&a, &n);

	if (n) {
		printf("original array: ");

		for (size_t i = 0; i < n; i++) {
			printf("%d ", *(a + i));
		}
		putchar('\n');

		inverse(a, n);

		printf("reversed array:");

		for (size_t i = 0; i < n; i++) {
			printf("%d ", *(a + i));
		}
		putchar('\n');

		free(a);
	}

	return 0;
}

void input_integer(int **a, size_t *n) {
	*a = NULL;
	*n = 0;

	printf("Enter array size: ");

	if (scanf("%zd", n) == 1 && *n != 0) {
		*a = malloc(*n * sizeof(int));

		printf("enter %zu integers: ", *n);
		for (size_t i = 0; i < *n; i++)
			scanf("%d", *a + i);
	}
}

void inverse(int *a, size_t n) {
	for (size_t i = 0; i < n / 2; i++) {
		int tmp = *(a + i);
		*(a + i) = *(a + n - i - 1);
		*(a + n - i - 1) = tmp;
	}
}
