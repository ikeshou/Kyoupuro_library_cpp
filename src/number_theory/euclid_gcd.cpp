#include "all.h"



namespace inner_euclid_gcd {
    /**
     * a >= b >= 0 の仮定のもと gcd(a, b) を計算する、euclid_gcd の内部関数
     */
    i64 gcd(i64 a, i64 b) {
        if (b == 0) {
            return a;
        }
        return inner_euclid_gcd::gcd(b, a % b);
    }
}


/**
 * O(lg(a + b)) でユークリッドの互除法により gcd(a, b) を計算
 * a, b に負の値が指定された場合 gcd(abs(a), abs(b)) が返る
 */
i64 euclid_gcd(i64 a, i64 b) {
    auto p = minmax(abs(a), abs(b));
    b = p.first;
    a = p.second;
    return inner_euclid_gcd::gcd(a, b);
}



namespace inner_euclid_ext_gcd {
    /**
     * a >= b >= 0 の仮定のもと ext_gcd(a, b) を計算する、euclid_ext_gcd の内部関数
     */
    tuple<i64, i64, i64> ext_gcd(i64 a, i64 b) {
        if (b == 0) {
            return {1, 0, a};
        }
        i64 q = a / b;
        i64 r = a % b;
        auto [s, t, d] = inner_euclid_ext_gcd::ext_gcd(b, r);
        i64 x = t;
        i64 y = s - q * t;
        return {x, y, d};
    }
}


/**
 * O(lg(a + b)) で拡張ユークリッドの互除法により ax + by = d (=gcd(a, b)) なる x, y, d を計算
 * d は常に正だが、x, y に負の値が返ることもある
 */
tuple<i64, i64, i64> euclid_ext_gcd(i64 a, i64 b) {
    // abs(a) < abs(b) の場合は交換する。解の x, y を入れ替えれば辻褄があう
    bool swapped = (abs(a) < abs(b));
    if (swapped) {
        swap(a, b);
    }
    // 負の場合は正に変換して計算をする。解の x, y の符号を反転すれば辻褄があう
    i32 sign_x = a >= 0 ? 1 : -1;
    i32 sign_y = b >= 0 ? 1 : -1;
    auto [x, y, d] = inner_euclid_ext_gcd::ext_gcd(abs(a), abs(b));
    if (swapped) {
        return {sign_y * y, sign_x * x, d};
    } else {
        return {sign_x * x, sign_y * y, d};
    }
}
