#include "all.h"


/**
 * O(lgr) で a ^ r (mod m) を計算
 */
i64 modpow(i64 a, i64 r, i64 mod) {
    if (!(r >= 0 && mod > 0)) {
        throw domain_error("modpow(): invalid arguments. r and mod should be r >=0 and mod > 0.");
    }
    if (r == 0) {
        return 1;
    }
    if (r % 2 == 0) {
        i64 tmp = modpow(a, r / 2, mod);
        return (tmp * tmp) % mod;
    } else {
        return (a * modpow(a, r - 1, mod)) % mod;
    }
}