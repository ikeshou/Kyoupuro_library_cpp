#include <gtest/gtest.h>
#include "all.h"
#include "number_theory/modpow.h"
#include "others/randint.h"


/**
 * Iteration 回 a, r をランダム生成して繰り返し二乗法で計算。
 * ナイーブに累乗 and 剰余計算をして求めた計算結果と比較するテストを行う。
 */
TEST(test_modpow, random_case) {
    i32 Iteration = 1000;
    i64 mod = 1000000007;
    for (i32 i = 0; i < Iteration; ++i) {
        i64 a = randint(-100, 100);
        i64 r = randint(0, 100);
        i64 expected = 1;
        for (i32 j = 0; j < r; ++j) expected = (a * expected) % mod;
        EXPECT_EQ(expected, modpow(a, r, mod));
    }
}
