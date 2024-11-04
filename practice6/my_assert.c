#include <stdio.h>
#include <stdlib.h>

#define my_assert(expression)						\
	((expression)							\
	 	? (void)0						\
		: my_assert_fail(#expression, __FILE__, __LINE__))

void my_assert_fail(const char *expression, const char *file, int line) {
	fprintf(stderr, "Assertion failed: %s, file %s, line %d\n", expression, file, line);
	abort();
}
