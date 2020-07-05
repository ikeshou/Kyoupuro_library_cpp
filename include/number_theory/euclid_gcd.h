#pragma once
#include "all.h"

i64 euclid_gcd(i64 a, i64 b);

namespace inner_euclid_gcd {
    i64 gcd(i64 a, i64 b);
}

tuple<i64, i64, i64> euclid_ext_gcd(i64 a, i64 b);

namespace inner_euclid_ext_gcd {
    tuple<i64, i64, i64> ext_gcd(i64 a, i64 b);
}