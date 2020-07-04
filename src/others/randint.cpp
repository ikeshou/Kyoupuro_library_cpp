#include "all.h"


/**
 * a <= x <= b なる整数 x をランダムに返す（擬似乱数）
 */
i32 randint(i32 a, i32 b) {
    assert(a <= b);
    return a + (i32)(rand() * (b - a + 1.0) / (1.0 + RAND_MAX));
}