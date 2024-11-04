#include <stdio.h>
#include <string.h>
#include <errno.h>

void my_perror(const char *message) {
	if (message && *message) {
		fprintf(stderr, "%s: %s\n", message, strerror(errno));
	} else {
		fprintf(stderr, "%s\n", strerror(errno));
	}
}
