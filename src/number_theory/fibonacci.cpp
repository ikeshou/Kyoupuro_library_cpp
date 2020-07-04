#include "all.h"


/**
 * O(n) で n 番目 (0-index) のフィボナッチ数 (1 始まり。1, 1, 2, 3, ...) を計算
 */
i64 fibonacci(i64 n, i64 a=1, i64 b=0) {
    if (n == 0) {
        return a;
    }
    return fibonacci(n - 1, a + b, a);
}