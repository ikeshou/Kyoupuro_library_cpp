#include "all.h"


/**
 * O(lg(max(a, b))) でユークリッドの互除法により gcd(a, b) を計算
 * a, b に負の値が指定された場合 gcd(abs(a), abs(b)) が返る
 */
i64 euclid_gcd(i64 a, i64 b) {
    auto p = minmax(abs(a), abs(b));
    b = p.first;
    a = p.second;
    if (b == 0) {
        return a;
    }
    return euclid_gcd(b, a % b);
}