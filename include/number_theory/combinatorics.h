#pragma once
#include "all.h"

struct Pascal {
    i64 n;
    VVL pascal;

    Pascal(i64 num);
    i64 comb(i64 a, i64 b);
};

