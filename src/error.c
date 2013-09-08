#include "error.h"

#include <stdio.h>
#include <stdlib.h>

void fatal_error(const char *reason) {
    fprintf(stderr, reason);
    exit(1);
}
