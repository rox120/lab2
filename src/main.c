#include <stdio.h>
#include "calculator.h"

int main() {
	int a = 10, b = 5;

	printf("Add: %d\n", add(a, b));
	printf("Subtract: %d\n", subtract(a, b));
	printf("Multiply: %d\n", multiply(a, b));
	printf("Divide: %.2f\n", divide(a, b));

	return 0;
}
