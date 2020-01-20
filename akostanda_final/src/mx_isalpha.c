#include "pathfinder.h"

bool mx_isalpha(int c) {
    bool y;

    if ((c > 64 && c < 91) || (c > 96 && c < 123)) {
        y = true;
    }
    else {
        y = false;
    }
    return y;
}
