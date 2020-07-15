#pragma once
#include "all.h"

struct UFtree {
    i64 num_of_elm;
    VL par;
    VL rank;
    VL group_size;
    UFtree(i64 num_of_elm);
    i64 find_root(i64 x);
    bool is_same(i64 x, i64 y);
    bool unite(i64 x, i64 y);
    i64 akin_num(i64 x);
};
