#include <stdlib.h>
#include "random.h"

int nextInt(int max) {
    return rand() % max + 1;
}
