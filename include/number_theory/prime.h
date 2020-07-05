#pragma once
#include "all.h"

bool is_prime(i64 num);

VL enum_divisor(i64 num);

struct Eratos {
    i64 table_max;
    VB table;

    Eratos(i64 num);
    bool is_prime(i64 num);
    unordered_map<i64, i64> prime_factorize(i64 num);
};