#include "utils.h"
#include "math.h"

int closestPow2(int n) {
    int res = 1;
    while (res <= n) {
        res = res * 2;
    }
    return res/2;
}

int intlog(int base, int x) {
    return (int)(log(x) / log(base));
}
