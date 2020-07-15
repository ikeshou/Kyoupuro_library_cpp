#include <gtest/gtest.h>
#include "all.h"
#include "number_theory/combinatorics.h"
#include "others/randint.h"


/**
 * n = 15 とする。0 <= j <= i <= n なるあらゆる i, j について combination(i, j) を階乗を用いて計算する。
 * パスカルの三角形から求めた値と一致するか検証する。
 */
TEST(test_pascal, comb_method) {
    i32 n = 15;
    Pascal p(n);
    VL factorial(n + 1, 1);
    for (i32 i = 2; i < (i32)factorial.size(); ++i) factorial[i] = factorial[i-1] * i;
    for (i32 i = 0; i <= n; ++i) {
        for (i32 j = 0; j <= i; ++j) {
            i64 expected = (factorial[i] / factorial[j]) / factorial[i-j];
            EXPECT_EQ(expected, p.comb(i, j));
        }
    }
}